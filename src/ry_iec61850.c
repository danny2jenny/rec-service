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

// 服务端口号
int iedPort = RY_61850_PORT;

volatile int inited_61850 = 0; // 是否得到过61850的配置

// 61850 设备配置列表
RY_61850_LN *ry_ln_list = NULL;

// 61850 模型
IedModel *model = NULL;

// 61850 服务
IedServer iedServer = NULL;

// -----------------节点配置--------------------

char iedName[100] = "RYTEC";
char dsName[100] = "dsIAS";
char ldName[100] = "SENSOR";

char lnValue[100] = "value";
char lnValueInput[100] = "value";
char lnValueAnalog[100] = "value";

char reportName[100] = "ryReport";
// --------------------------------------------

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
 * 清除配置
 */
void IEC61850CleanConfig() {
    RY_61850_LN *device_ln, *tmp_nvr;
    // 遍历 NVR 记录，删除所有的
    HASH_ITER(hh, ry_ln_list, device_ln, tmp_nvr) {
        HASH_DEL(ry_ln_list, device_ln);
        free(device_ln);
    }
}

/**
 * 更新数据
 */

void IEC61850UpdateBoolean(LogicalNode *ln, uint64_t timestamp, bool value) {
    DataAttribute *dataAttribute;
    dataAttribute = (DataAttribute *) ModelNode_getChild((ModelNode *) ln, "value.stVal");
    IedServer_updateBooleanAttributeValue(iedServer, dataAttribute, value);

    dataAttribute = (DataAttribute *) ModelNode_getChild((ModelNode *) ln, "value.t");
    IedServer_updateUTCTimeAttributeValue(iedServer, dataAttribute, timestamp);
}

void IEC61850UpdateAnalog(LogicalNode *ln, uint64_t timestamp, float value) {
    DataAttribute *dataAttribute;
    dataAttribute = (DataAttribute *) ModelNode_getChild((ModelNode *) ln, "value.instMag.f");
    IedServer_updateFloatAttributeValue(iedServer, dataAttribute, value);
    dataAttribute = (DataAttribute *) ModelNode_getChild((ModelNode *) ln, "value.t");
    IedServer_updateUTCTimeAttributeValue(iedServer, dataAttribute, timestamp);
}

/**
 * 解析配置
 */
void IEC61850ParseConfig(char *cfgStr) {
    //-----------------读取配置-----------------------
    ini_t *config = ini_load(ini_file_path);

    ini_sget(config, "61850", "iedName", "%s", iedName);
    ini_sget(config, "61850", "dsName", "%s", dsName);
    ini_sget(config, "61850", "ldName", "%s", ldName);
    ini_sget(config, "61850", "lnValue", "%s", lnValue);
    ini_sget(config, "61850", "lnValueInput", "%s", lnValueInput);
    ini_sget(config, "61850", "lnValueAnalog", "%s", lnValueAnalog);
    ini_sget(config, "61850", "reportName", "%s", reportName);
    ini_sget(config, "61850", "port", "%d", &iedPort);

    ini_free(config);
    // ---------------------------------------------

    IEC61850Cleanup();
    IEC61850CleanConfig();

    RY_61850_LN *ln_rec;    // 建立的新的配置文件的节点

    // --------------------------- 61850 模型-------------------------------------
    model = IedModel_create(iedName);

    LogicalDevice *logic_device = LogicalDevice_create(ldName, model);

    LogicalNode *lln0 = LogicalNode_create("LLN0", logic_device);

    DataObject *lln0_mod = CDC_ENS_create("Mod", (ModelNode *) lln0, 0);
    DataObject *lln0_health = CDC_ENS_create("Health", (ModelNode *) lln0, 0);

    SettingGroupControlBlock_create(lln0, 1, 1);


    // 生成报告
    DataSet *dataSet = DataSet_create(dsName, lln0);

    // 新的节点变量
    LogicalNode *logicalNode;             // 逻辑节点
    char str_buf[100];                    // 字符串buffer
    char rpt_buf[500];                    // 报告相关的字符串

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
                strcpy(str_buf, LN_NAME_INPUT);                                     //LN_NAME_INPUT = CALH
                sprintf(str_buf + strlen(LN_NAME_INPUT), "%d", ln_rec->id);

                // 创建逻辑节点了数据
                logicalNode = LogicalNode_create(str_buf, logic_device);
                CDC_SPC_create("value", (ModelNode *) logicalNode, 0, false);

                // 逻辑节点保存在配置文件
                ln_rec->ln = logicalNode;

                // 报告数据
                sprintf(rpt_buf, "%s%s%s%s", str_buf, "$ST$", lnValue, "$stVal");
                DataSetEntry_create(dataSet, rpt_buf, -1, NULL);

                break;
            case LN_TYPE_ANALOG:            // 模拟量节点
                // 得到逻辑节点的名称
                strcpy(str_buf, LN_NAME_ANALOG);                                    //LN_NAME_INPUT = MMXU
                sprintf(str_buf + strlen(LN_NAME_ANALOG), "%d", ln_rec->id);

                // 创建逻辑节点和数据
                logicalNode = LogicalNode_create(str_buf, logic_device);
                CDC_SAV_create("value", (ModelNode *) logicalNode, 0, false);

                // 逻辑节点保存在配置文件
                ln_rec->ln = logicalNode;

                // 报告数据
                sprintf(rpt_buf, "%s%s%s%s", str_buf, "$MX$", lnValue, "$instMag");
                DataSetEntry_create(dataSet, rpt_buf, -1, NULL);

                break;
            case LN_TYPE_SWITCH:            // 开关节点
                // 用于开关控制，暂时没有实现
                //LN_NAME_INPUT = GGIO

                break;
        }

        HASH_ADD_INT(ry_ln_list, id, ln_rec);
    }


    // 生成报告
    uint8_t rptOptions = RPT_OPT_SEQ_NUM | RPT_OPT_TIME_STAMP | RPT_OPT_REASON_FOR_INCLUSION;

    ReportControlBlock_create(reportName, lln0, reportName, false, dsName, 1, TRG_OPT_DATA_CHANGED,
                              rptOptions, 50, 0);
    //ReportControlBlock_create("events01", lln0, "events01", false, NULL, 1, TRG_OPT_DATA_CHANGED, rptOptions, 50, 0);
    //ReportControlBlock_create("events02", lln0, "events02", false, dataSet, 1, TRG_OPT_DATA_CHANGED, rptOptions, 50, 0);

    /**
     * todo: 开启Goose
     * 需要指定网卡，并要使用特权用户
     */

    // GSEControlBlock_create("gse01", lln0, "events01", "events", 1, false, 200, 3000);


    // 启动服务器
    IEC61850Start();

    // -------------------- 为模型填充初始值 ---------------------

    IedServer_lockDataModel(iedServer);

    bool state_bool;            // 逻辑量
    float state_float;          // 浮点数
    uint64_t timestamp;         // 更新时间
    timestamp = Hal_getTimeInMs();

    int device_id;

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
                state_bool = json_object_get_boolean(runtime_object, "state");
                IEC61850UpdateBoolean(ln_rec->ln, timestamp, state_bool);
                break;
            case LN_TYPE_ANALOG:            // 模拟量节点
                state_float = json_object_dotget_number(runtime_object, "state.value");
                IEC61850UpdateAnalog(ln_rec->ln, timestamp, state_float);
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
    RY_61850_LN *ln_rec;        // 设备的节点
    uint64_t timestamp;         // 更新时间


    root_value = json_parse_string(str);
    root_object = json_value_get_object(root_value);
    runtime_object = json_object_get_object(root_object, "payload");

    device_type = json_object_dotget_number(runtime_object, "device.type");
    device_id = json_object_dotget_number(runtime_object, "device.id");


    // 通过device id 查找列表中的对象
    HASH_FIND_INT(ry_ln_list, &device_id, ln_rec);

    if (ln_rec == NULL) {
        return;
    }

    bool state_bool;            // 逻辑量
    float state_float;          // 浮点数

    timestamp = Hal_getTimeInMs();

    IedServer_lockDataModel(iedServer);
    switch (device_type) {
        case LN_TYPE_INPUT:
            state_bool = json_object_dotget_boolean(runtime_object, "runtime.state");
            IEC61850UpdateBoolean(ln_rec->ln, timestamp, state_bool);
            break;
        case LN_TYPE_ANALOG:
            state_float = json_object_dotget_number(runtime_object, "runtime.state.value");
            IEC61850UpdateAnalog(ln_rec->ln, timestamp, state_float);
            break;
    }
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