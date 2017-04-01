//
// Created by Danny on 2017/3/19.
//

#ifndef RY_MSG_H
#define RY_MSG_H
#ifdef __cplusplus
extern "C" {
#endif

// *************************常量定义***********************************

/**
 * 1-100    服务器发送的消息
 * 101-200  发送给服务器的消息
 */
#define MQTT_CMD_VIDEO_INIT     1       // 初始化
#define MQTT_CMD_VIDEO_PTZ      2       // PTZ命令


#define MQTT_CMD_INIT_REQUEST   101     // 请求初始化
#define MQTT_CMD_VIDEO_INFO     102     // Video 主动发送的消息

// 初始化MQTT消息
int ry_msg_init(char *host, int port);

// 发送消息
int mqtt_send_to_mc(int cmd, char *payload, int len);

// 清理资源
void mqtt_cleanup();

#ifdef __cplusplus
}
#endif
#endif
