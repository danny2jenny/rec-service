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
*/

#include <parson/parson.h>
#include <ut/uthash.h>
#include <stdio.h>

#include "iec61850/iec61850_server.h"
#include "iec61850/hal_thread.h"
#include "iec61850.h"
#include "config.h"
#include "ry_msg.h"

// 服务端口号
int tcpPort = RY_61850_PORT;

volatile int inited_61850 = 0; // 是否得到过61850的配置

// 61850 设备配置列表
RY_61850_LN *ry_ln_list = NULL;

// 61850 模型
IedModel *model = NULL;

// 61850 服务
IedServer iedServer = NULL;

/**
 * 释放资源
 */
void iec61850_cleanup() {
    if (iedServer == NULL) {
        return;
    }
    IedServer_stop(iedServer);
    IedServer_destroy(iedServer);
    IedModel_destroy(model);
}

/**
 * 清除配置
 */
void cleanConfig() {
    RY_61850_LN *device_ln, *tmp_nvr;
    // 遍历 NVR 记录，删除所有的
    HASH_ITER(hh, ry_ln_list, device_ln, tmp_nvr) {
        HASH_DEL(ry_ln_list, device_ln);
        free(device_ln);
    }
}

/**
 * 解析配置
 */
void iec61850_parseConfig(char *cfgStr) {

    iec61850_cleanup();
    cleanConfig();

    RY_61850_LN *ln_rec;    // 建立的新的配置文件的节点

    // --------------------------- 61850 模型-------------------------------------
    model = IedModel_create(IEC61850_IED_NAME);

    LogicalDevice *lDevice1 = LogicalDevice_create(IEC61850_LD_NAME, model);

    LogicalNode *lln0 = LogicalNode_create("LLN0", lDevice1);

    DataObject *lln0_mod = CDC_ENS_create("Mod", (ModelNode *) lln0, 0);
    DataObject *lln0_health = CDC_ENS_create("Health", (ModelNode *) lln0, 0);

    SettingGroupControlBlock_create(lln0, 1, 1);

    LogicalNode *logicalNode;             // 逻辑节点

    char str_buf[100];                    // 字符串buffer

    // ---------------------------------------------------------------------------

    // *************json处理 生成61850模型*******************
    JSON_Value *root_value;
    JSON_Object *root_object, *device_all_object, *device_object, *runtime_object;
    JSON_Array *json_array;

    root_value = json_parse_string(cfgStr);

    root_object = json_value_get_object(root_value);                //json 根对象
    json_array = json_object_get_array(root_object, "payload");     //json payload 数组


    int i;
    for (i = 0; i < json_array_get_count(json_array); i++) {
        device_all_object = json_array_get_object(json_array, i);

        device_object = json_object_get_object(device_all_object, "device");

        ln_rec = malloc(sizeof(RY_61850_LN));
        ln_rec->id = json_object_get_number(device_object, "id");
        ln_rec->type = json_object_get_number(device_object, "type");

        switch (ln_rec->type) {
            case LN_TYPE_INPUT:             // 输入节点
                // 得到逻辑节点的名称
                strcpy(str_buf, LN_NAME_INPUT);
                sprintf(str_buf + strlen(LN_NAME_INPUT), "%d", ln_rec->id);

                logicalNode = LogicalNode_create(str_buf, lDevice1);
                CDC_SPC_create("value", (ModelNode *) logicalNode, 0, false);

                // 逻辑节点保存在配置文件
                ln_rec->ln = logicalNode;

                break;
            case LN_TYPE_ANALOG:            // 模拟量节点
                // 得到逻辑节点的名称
                strcpy(str_buf, LN_NAME_ANALOG);
                sprintf(str_buf + strlen(LN_NAME_ANALOG), "%d", ln_rec->id);

                logicalNode = LogicalNode_create(str_buf, lDevice1);
                CDC_SAV_create("value", (ModelNode *) logicalNode, 0, false);

                // 逻辑节点保存在配置文件
                ln_rec->ln = logicalNode;

                break;
            case LN_TYPE_SWITCH:            // 开关节点
                break;
        }

        HASH_ADD_INT(ry_ln_list, id, ln_rec);
    }


    // 启动服务器
    iec61850_start();

    // -------------------- 为模型填充初始值 ---------------------

    IedServer_lockDataModel(iedServer);

    bool state_bool;            // 逻辑量
    float state_float;          // 浮点数

    int device_id;
    DataAttribute *dataAttribute;

    // 再次遍历 json
    for (i = 0; i < json_array_get_count(json_array); i++) {
        device_all_object = json_array_get_object(json_array, i);

        device_object = json_object_get_object(device_all_object, "device");
        runtime_object = json_object_get_object(device_all_object, "runtime");

        device_id = json_object_get_number(device_object, "id");

        // 通过device id 查找列表中的对象
        HASH_FIND_INT(ry_ln_list, &device_id, ln_rec);

        if (ln_rec == NULL) {
            continue;
        }

        switch (ln_rec->type) {
            case LN_TYPE_INPUT:             // 输入节点
                dataAttribute = (DataAttribute *) ModelNode_getChild((ModelNode *) ln_rec->ln, "value.stVal");
                state_bool = json_object_get_boolean(runtime_object, "state");
                IedServer_updateBooleanAttributeValue(iedServer, dataAttribute, state_bool);

                dataAttribute = (DataAttribute *) ModelNode_getChild((ModelNode *) ln_rec->ln, "value.t");
                IedServer_updateUTCTimeAttributeValue(iedServer, dataAttribute, Hal_getTimeInMs());
                break;
            case LN_TYPE_ANALOG:            // 模拟量节点
                dataAttribute = (DataAttribute *) ModelNode_getChild((ModelNode *) ln_rec->ln, "value.instMag.f");
                state_float = json_object_dotget_number(runtime_object, "state.value");
                IedServer_updateFloatAttributeValue(iedServer, dataAttribute, state_float);


                dataAttribute = (DataAttribute *) ModelNode_getChild((ModelNode *) ln_rec->ln, "value.t");
                IedServer_updateUTCTimeAttributeValue(iedServer, dataAttribute, Hal_getTimeInMs());

                break;
            case LN_TYPE_SWITCH:            // 开关节点
                break;
        }

    }

    IedServer_unlockDataModel(iedServer);

    // ------------------ 释放Json资源 -------------------------/
    json_value_free(root_value);
}

/**
* 运行61850服务
*/
void iec61850_start() {
    iedServer = IedServer_create(model);

    /* MMS server will be instructed to start listening to client connections. */
    IedServer_start(iedServer, tcpPort);

    if (!IedServer_isRunning(iedServer)) {
        printf("Starting server failed! Exit.\n");
        IedServer_destroy(iedServer);
    }

}

/**
* 收到61850消息
*/
void iec61850_on_mqtt_message(int cmd, char *msg, int len) {

    switch (cmd) {
        case MQTT_CMD_61850_INIT:
            // 61850 初始化命令
            inited_61850 = 1;
            iec61850_parseConfig(msg);
            break;
        case MQTT_CMD_61850_UPDATE:
            // 61850 节点更新

            break;
    }
}

/**
 * 请求 61850 配置文件
*/
void ry_61850_request_config() {
    // 生成 Json 字符串
    JSON_Value *root_value = json_value_init_object();
    JSON_Object *root_object = json_value_get_object(root_value);
    char *serialized_string = NULL;

    json_object_set_number(root_object, "cmd", MQTT_CMD_61850_INIT_REQUEST);
    json_object_set_null(root_object, "payload");
    serialized_string = json_serialize_to_string_pretty(root_value);

    // 发送请求
    mqtt_publish(RY_VIDEO_PUB_TOPIC, serialized_string, strlen(serialized_string));

    // 释放资源
    json_free_serialized_string(serialized_string);
    json_value_free(root_value);
}

/**
 * 定时执行
*/
void ry_61850_ontime() {
    if (!inited_61850) {
        ry_61850_request_config();
    }
}