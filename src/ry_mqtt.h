//
// Created by Danny on 2017/3/19.
//

#ifndef RY_MQTT_H
#define RY_MQTT_H
#ifdef __cplusplus
extern "C" {
#endif

// *************************常量定义***********************************



// 初始化MQTT消息
int MqttInit(char *host, int port);

// 发布消息
void MqttPublish(char *topic, char *payload, int len);

// 发送消息
int MqttSendMsg(int cmd, char *payload, int len);

// 清理资源
void MqttClean();

#ifdef __cplusplus
}
#endif
#endif
