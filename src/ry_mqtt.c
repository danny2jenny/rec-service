/*******************************************************************************
 * MQTT 的消息订阅
 *******************************************************************************/

#include <stdio.h>
#include <mosquitto.h>
#include <parson/parson.h>

#include "ry_mqtt.h"
#include "ry_config.h"
#include "ry_iec61850.h"

struct mosquitto *mqtt = NULL;      // mqtt 控制对象
char out_buf[512];                  // 发送buffer

/**
 * 发送数据到mc
 * @param cmd
 * @param payload
 * @param len
 * @return
 */
int MqttSendMsg(int cmd, char *payload, int len) {
    // 命令头
    int head_leng = strlen(out_buf);
    // 复制payload
    memcpy(out_buf + head_leng, payload, len);
    mosquitto_publish(mqtt, NULL, RY_VIDEO_PUB_TOPIC, head_leng + len, out_buf, 2, false);
}

/**
 * 发布消息
 * @param topic
 * @param payload
 * @param len
 */
void MqttPublish(char *topic, char *payload, int len) {
    mosquitto_publish(mqtt, NULL, topic, len, payload, 2, false);
}

/**
 * 收到消息
 * @param mosq
 * @param userdata
 * @param message
 */
void MqttOnMsgReceive(struct mosquitto *mosq, void *userdata, const struct mosquitto_message *message) {

    // 解析命令
    JSON_Value *root_value;
    JSON_Object *root_object;

    root_value = json_parse_string(message->payload);
    root_object = json_value_get_object(root_value);
    int cmd = json_object_get_number(root_object, "cmd");

    /* cleanup code */
    json_value_free(root_value);

    if (cmd <= 100) {
        // 小于100是NVR消息
        // NvrOnMqttMsg(cmd, message->payload, message->payloadlen);
    } else {
        // 大于100是61850消息
        IEC61850OnMqttMsg(cmd, message->payload, message->payloadlen);
    }
}

/**
 * 连接后的回调，可能失败，也可能成功
 * @param mosq
 * @param userdata
 * @param result
 */
void MqttOnConnect(struct mosquitto *mosq, void *userdata, int result) {
    if (!result) {
        // 订阅
        mosquitto_subscribe(mosq, NULL, RY_VIDEO_SUB_TOPIC, 2);     // 订阅视频消息
    } else {
        fprintf(stderr, "Connect failed\n");
    }
}

/**
 * 断开连接的回调
 * @param mosq
 * @param userdata
 * @param result
 */
void MqttOnDisconnect(struct mosquitto *mosq, void *userdata, int result) {
    printf("Connect disable!!!\n");
}

/**
 * 订阅后的回调，可能失败也可能成功
 * @param mosq
 * @param userdata
 * @param mid
 * @param qos_count
 * @param granted_qos
 */
void MqttOnSubscribe(struct mosquitto *mosq, void *userdata, int mid, int qos_count, const int *granted_qos) {
    int i;

    printf("Subscribed (mid: %d): %d", mid, granted_qos[0]);
    for (i = 1; i < qos_count; i++) {
        printf(", %d", granted_qos[i]);
    }
    printf("\n");
}

/**
 * MQTT的调试信息
 * @param mosq
 * @param userdata
 * @param level
 * @param str
 */
void MqttOnLog(struct mosquitto *mosq, void *userdata, int level, const char *str) {
    /* Pring all log messages regardless of level. */
#ifdef _TEST
    printf("%s\n", str);
#endif
}

/**
 * MQTT 初始化
 * @param host
 * @param port
 * @return
 */
int MqttInit(char *host, int port) {

    int keepalive = 60;
    bool clean_session = true;

    mosquitto_lib_init();
    mqtt = mosquitto_new("ID_RY_VIDEO_SERVICE", clean_session, NULL);
    if (!mqtt) {
        fprintf(stderr, "Error: Out of memory.\n");
        return 1;
    }

    // 设置回调
    mosquitto_log_callback_set(mqtt, MqttOnLog);                      // 日志回调
    mosquitto_connect_callback_set(mqtt, MqttOnConnect);              // 连接回调
    mosquitto_disconnect_callback_set(mqtt, MqttOnDisconnect);        // 断开连接
    mosquitto_message_callback_set(mqtt, MqttOnMsgReceive);           // 收到消息
    mosquitto_subscribe_callback_set(mqtt, MqttOnSubscribe);          // 订阅回调

    // 链接代理
    mosquitto_connect_async(mqtt, host, port, keepalive);
    mosquitto_loop_start(mqtt);

    return 0;
}

/**
 * 释放资源
 */
void MqttClean() {
    // 清理 MQTT 通讯
    mosquitto_destroy(mqtt);
    mosquitto_lib_cleanup();
}
