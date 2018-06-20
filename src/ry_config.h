/**
 * 服务的所有配置信息
 */

#ifndef RY_CONFIG_H
#define RY_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif
//------------------------------------

// MQTT 消息主题
#define RY_VIDEO_SUB_TOPIC "rec/srv/video/to"           // 订阅主题
#define RY_VIDEO_PUB_TOPIC "rec/srv/video/from"         // 发送主题

// -------------------61850配置--------------------
#define RY_61850_PORT 102                               // 61850 端口，通过配置文件进行配置

#define LN_TYPE_INPUT    102                            // 遥信
#define LN_TYPE_ANALOG   201                            // 遥测
#define LN_TYPE_SWITCH   101                            // 遥控

// device 常量
#define DEVICE_ON       21                              // 开关为开的常量
#define DEVICE_OFF      20
//------------------------------------
#ifdef __cplusplus
}
#endif

#endif //RY_CONFIG_H
