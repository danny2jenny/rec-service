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
#define RY_MQTT_SUB_TOPIC "rec/srv/video"       // 订阅主题
#define RY_MQTT_PUB_TOPIC "rec/mc/info"         // 发送主题

//------------------------------------
#ifdef __cplusplus
}
#endif

#endif //RY_SERVICE_CONFIG_H
