/**
* 61850 服务
*/

#include <parson/parson.h>
#include <ut/uthash.h>
#include <stdio.h>

#include "iec61850/iec61850_server.h"
#include "iec61850/hal_thread.h"
#include "iec61850.h"
#include "config.h"
#include "ry_msg.h"
#include "model.h"

// 服务端口号
int tcpPort = RY_61850_PORT;
volatile int inited_61850 = 0; // 是否得到过61850的配置

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
    LogicalNode *lln0 = LN_LLN0_createInstance("LLN0", lDevice1);

    SettingGroupControlBlock_create(lln0, 1, 1);

    LogicalNode *logicalNode;             // 逻辑节点

    char str_buf[100];                    // 字符串buffer

    // ---------------------------------------------------------------------------

    // *************json处理*******************
    JSON_Value *root_value;
    JSON_Object *root_object, *config_object, *device_object;
    JSON_Array *json_array;

    root_value = json_parse_string(cfgStr);

    root_object = json_value_get_object(root_value);
    json_array = json_object_get_array(root_object, "payload");


    int i;
    for (i = 0; i < json_array_get_count(json_array); i++) {
        config_object = json_array_get_object(json_array, i);

        device_object = json_object_get_object(config_object, "device");

        ln_rec = malloc(sizeof(RY_61850_LN));
        ln_rec->id = json_object_get_number(device_object, "id");
        ln_rec->type = json_object_get_number(device_object, "type");

        switch (ln_rec->type) {
            case LN_TYPE_INPUT:             // 输入节点
                // 得到逻辑节点的名称
                strcpy(str_buf, LN_NAME_INPUT);
                sprintf(str_buf + strlen(LN_NAME_INPUT), "%d", ln_rec->id);

                logicalNode = LN_CALH_createInstance(str_buf, lDevice1);

                // 逻辑节点保存在配置文件
                ln_rec->ln = logicalNode;

                break;
            case LN_TYPE_ANALOG:            // 模拟量节点
                // 得到逻辑节点的名称
                strcpy(str_buf, LN_NAME_ANALOG);
                sprintf(str_buf + strlen(LN_NAME_ANALOG), "%d", ln_rec->id);

                logicalNode = LN_MMXU_createInstance(str_buf, lDevice1);

                // 逻辑节点保存在配置文件
                ln_rec->ln = logicalNode;

                break;
            case LN_TYPE_SWITCH:            // 开关节点
                break;
        }

        HASH_ADD_INT(ry_ln_list, id, ln_rec);
    }

    /* cleanup code */
    json_value_free(root_value);

    iec61850_start();
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
            inited_61850 = 1;
            iec61850_parseConfig(msg);
            break;
        case MQTT_CMD_61850_UPDATE:
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