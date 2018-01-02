/**
 * 61850 服务
 *
 * 公共数据类
 * CDC_SPS_create 创建单点状态
 * CDC_DPS_create 创建双点状态
 * CDC_SAV_create 采样值
 * CDC_SPC_create 单点控制
 * CDC_DPC_create 双点控制
 *
 * http://www.doc88.com/p-9915328896975.html
 *
*/

#include <parson/parson.h>
#include <ut/uthash.h>
#include <stdio.h>

#include "iec61850/iec61850_server.h"
#include "ry_iec61850.h"
#include "ry_config.h"
#include "ry_mqtt.h"
#include "ini.h"

// 是否得到过61850的配置
volatile int inited_61850 = 0;

// 61850 模型
IedModel *model = NULL;

// 61850 服务
IedServer iedServer = NULL;

// -----------------61850 配置信息--------------------
// 服务端口号
int iedPort = RY_61850_PORT;
// 配置文件
char cfgFile[200] = "/home/danny/ivs.cfg";

/**
 * 释放资源
 */
void IEC61850Cleanup() {
    if (iedServer == NULL) {
        return;
    }
    IedServer_stop(iedServer);
    IedServer_destroy(iedServer);
    IedModel_destroy(model);
}

/**
 * 更新一个节点的值
 * @param type
 * @param val
 */
void updateNodeValue(int type, int device_id, float val) {

    uint64_t timestamp = Hal_getTimeInMs();
    ModelNode *mn;
    int stateVal = 20;

    switch (type) {
        case LN_TYPE_INPUT:
            // 更新值
            mn = IedModel_getModelNodeByShortAddress(model, device_id);
            if (mn == NULL) {
                return;
            }

            if (val > 0) {
                IedServer_updateBooleanAttributeValue(iedServer, mn, true);
            }

            if (val <= 0) {
                IedServer_updateBooleanAttributeValue(iedServer, mn, false);
            }

            // 更新时间
            mn = mn->parent;
            if (mn){
                mn = ModelNode_getChild(mn, "t");
            } else {
                return;
            }
            if (mn){
                IedServer_updateUTCTimeAttributeValue(iedServer, mn, timestamp);
            }

            break;
        case LN_TYPE_ANALOG:
            // 更新值
            mn = IedModel_getModelNodeByShortAddress(model, device_id);
            if (mn == NULL) {
                return;
            }
            IedServer_updateFloatAttributeValue(iedServer, mn, val);

            // 更新时间
            mn = mn->parent;   // mag 节点
            if (mn){
                mn = mn->parent;  // MMXN 节点
            } else {
                return;
            }

            if (mn){
                mn = mn = ModelNode_getChild(mn, "t");
            } else {
                return;
            }

            if (mn){
                IedServer_updateUTCTimeAttributeValue(iedServer, mn, timestamp);
            }

            break;
        case LN_TYPE_SWITCH:
            stateVal = val;
            // 更新值
            mn = IedModel_getModelNodeByShortAddress(model, device_id);
            if (mn == NULL) {
                return;
            }

            if (stateVal == DEVICE_ON) {
                IedServer_updateBooleanAttributeValue(iedServer, mn, true);
            } else {
                IedServer_updateBooleanAttributeValue(iedServer, mn, false);
            }

            // 更新时间
            mn = mn->parent;
            if (mn){
                mn = ModelNode_getChild(mn, "t");
            } else {
                return;
            }

            if (mn){
                IedServer_updateUTCTimeAttributeValue(iedServer, mn, timestamp);
            }
            break;
    }
}


/**
 * 控制回调
 * @param parameter
 * @param value
 * @param test
 * @return
 */
static ControlHandlerResult controlHandlerForBinaryOutput(void *parameter, MmsValue *value, bool test) {
    bool state = false;
    state = MmsValue_getBoolean(value);
    int device = parameter;

    // 生成 Json 字符串
    JSON_Value *root_value = json_value_init_object();
    JSON_Object *root_object = json_value_get_object(root_value);
    char *serialized_string = NULL;

    json_object_set_number(root_object, "cmd", MQTT_CMD_61850_SWITCH);
    json_object_set_null(root_object, "payload");


    json_object_set_number(root_object, "device", (double)device);

    if (state){
        json_object_set_boolean(root_object, "val", true);
    } else {
        json_object_set_boolean(root_object, "val", false);
    }

    serialized_string = json_serialize_to_string_pretty(root_value);

    // 发送请求
    MqttPublish(RY_VIDEO_PUB_TOPIC, serialized_string, strlen(serialized_string));

    // 释放资源
    json_free_serialized_string(serialized_string);
    json_value_free(root_value);
}

/**
 * 解析配置
 */
void IEC61850ParseConfig(char *cfgStr) {
    //-----------------读取配置-----------------------
    ini_t *config = ini_load(ini_file_path);

    // 端口号
    ini_sget(config, "61850", "port", "%d", &iedPort);
    // 配置文件
    ini_sget(config, "61850", "cfgFile", "%s", cfgFile);

    ini_free(config);

    // --------------清理以前的61850配置---------------
    IEC61850Cleanup();

    // ------------------读取模型配置-----------------------
    /* open configuration file */
    FileHandle configFile = FileSystem_openFile(cfgFile, false);

    if (configFile == NULL) {
        printf("Error opening config file!\n");
        return;
    }

    /* parse the configuration file and create the data model */
    model = ConfigFileParser_createModelFromConfigFile(configFile);

    FileSystem_closeFile(configFile);

    if (model == NULL) {
        printf("Error parsing config file!\n");
        return;
    }

    // *************json处理 生成61850模型*******************
    JSON_Value *root_value;
    JSON_Object *root_object, *device_all_object, *device_object, *runtime_object;
    JSON_Array *json_array;

    root_value = json_parse_string(cfgStr);

    root_object = json_value_get_object(root_value);                //json 根对象
    json_array = json_object_get_array(root_object, "payload");     //json payload 数组


    // 启动服务器
    IEC61850Start();

    // -------------------- 为模型填充初始值 ---------------------

    IedServer_lockDataModel(iedServer);
    float val;                  // 值
    int device_type, device_id;
    ModelNode *ctlNodeST, *ctlNode;      // 控制节点
    //遍历 json
    int i;

    for (i = 0; i < json_array_get_count(json_array); i++) {
        device_all_object = json_array_get_object(json_array, i);

        device_object = json_object_get_object(device_all_object, "device");
        runtime_object = json_object_get_object(device_all_object, "runtime");

        device_id = json_object_get_number(device_object, "id");
        device_type = json_object_get_number(device_object, "type");

        // 设置值
        switch (device_type) {
            case LN_TYPE_INPUT:             // 输入节点
                val = json_object_dotget_boolean(runtime_object, "state");
                break;
            case LN_TYPE_ANALOG:            // 模拟量节点
                val = json_object_dotget_number(runtime_object, "state.value");
                break;
            case LN_TYPE_SWITCH:            // 开关节点
                val = json_object_dotget_number(runtime_object, "state.output");

                // 设置回调
                // 找到开关的ST
                ctlNodeST = IedModel_getModelNodeByShortAddress(model, device_id);
                if (ctlNodeST) {
                    // 通过 ST 找到开关的父节点
                    ctlNode = ctlNodeST->parent;
                    if (ctlNode) {
                        IedServer_setControlHandler(iedServer, ctlNode, (ControlHandler) controlHandlerForBinaryOutput,
                                                    device_id);
                    }
                }
                break;
        }
        updateNodeValue(device_type, device_id, val);

    }

    IedServer_unlockDataModel(iedServer);

    // ------------------ 释放Json资源 -------------------------/
    json_value_free(root_value);
}

/**
* 运行61850服务
*/
void IEC61850Start() {
    iedServer = IedServer_create(model);

    /* MMS server will be instructed to start listening to client connections. */
    IedServer_start(iedServer, iedPort);

    if (!IedServer_isRunning(iedServer)) {
        printf("Starting server failed! Exit.\n");
        IedServer_destroy(iedServer);
    }

}

/**
 * 通过json来更新一个设备
 */
void IEC61850UpdateDevice(char *str) {
    // 解析命令
    JSON_Value *root_value;
    JSON_Object *root_object, *runtime_object;
    int device_type, device_id;

    root_value = json_parse_string(str);
    root_object = json_value_get_object(root_value);
    runtime_object = json_object_get_object(root_object, "payload");

    device_type = json_object_dotget_number(runtime_object, "device.type");
    device_id = json_object_dotget_number(runtime_object, "device.id");

    float val;
    IedServer_lockDataModel(iedServer);
    // 设置值
    switch (device_type) {
        case LN_TYPE_INPUT:             // 输入节点
            val = json_object_dotget_boolean(runtime_object, "runtime.state");
            break;
        case LN_TYPE_ANALOG:            // 模拟量节点
            val = json_object_dotget_number(runtime_object, "runtime.state.value");
            break;
        case LN_TYPE_SWITCH:            // 开关节点
            val = json_object_dotget_number(runtime_object, "runtime.state.output");
            break;
    }

    updateNodeValue(device_type, device_id, val);

    IedServer_unlockDataModel(iedServer);

    // 释放资源
    json_value_free(root_value);
}

/**
* 收到61850消息
*/
void IEC61850OnMqttMsg(int cmd, char *msg, int len) {

    switch (cmd) {
        case MQTT_CMD_61850_INIT:
            // 61850 初始化命令
            inited_61850 = 1;
            IEC61850ParseConfig(msg);
            break;
        case MQTT_CMD_61850_UPDATE:
            // 61850 节点更新
            IEC61850UpdateDevice(msg);
            break;
    }
}

/**
 * 请求 61850 配置文件
*/
void IEC61850RequestCfg() {
    // 生成 Json 字符串
    JSON_Value *root_value = json_value_init_object();
    JSON_Object *root_object = json_value_get_object(root_value);
    char *serialized_string = NULL;

    json_object_set_number(root_object, "cmd", MQTT_CMD_61850_INIT_REQUEST);
    json_object_set_null(root_object, "payload");
    serialized_string = json_serialize_to_string_pretty(root_value);

    // 发送请求
    MqttPublish(RY_VIDEO_PUB_TOPIC, serialized_string, strlen(serialized_string));

    // 释放资源
    json_free_serialized_string(serialized_string);
    json_value_free(root_value);
}

/**
 * 定时执行
*/
void IEC61850OnTimer() {
    if (!inited_61850) {
        IEC61850RequestCfg();
    }
}