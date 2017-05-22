/**
 * 服务的所有配置信息
 */

#ifndef RY_SERVICE_CONFIG_H
#define RY_SERVICE_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif
//------------------------------------

// MQTT 消息主题
#define RY_VIDEO_SUB_TOPIC "rec/srv/video/to"           // 订阅主题
#define RY_VIDEO_PUB_TOPIC "rec/srv/video/from"         // 发送主题

#define RY_61850_SUB_TOPIC "rec/srv/61850/to"           // 61850 订阅
#define RY_61850_PUB_TOPIC "rec/srv/61850/from"         // 61850 发布

//------------------------------------
#ifdef __cplusplus
}
#endif

#endif //RY_SERVICE_CONFIG_H
