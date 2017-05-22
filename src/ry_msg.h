//
// Created by Danny on 2017/3/19.
//

#ifndef RY_MSG_H
#define RY_MSG_H
#ifdef __cplusplus
extern "C" {
#endif

// *************************常量定义***********************************



// 初始化MQTT消息
int ry_msg_init(char *host, int port);

// 发布消息
void mqtt_publish(char *topic, char *payload, int len);

// 发送消息
int mqtt_send_to_mc(int cmd, char *payload, int len);

// 清理资源
void mqtt_cleanup();

#ifdef __cplusplus
}
#endif
#endif
