//
// 
//

#ifndef RY_ICE61850_H
#define RY_ICE61850_H

#ifdef __cplusplus
extern "C" {
#endif
//********************************

#include <ut/uthash.h>
#include <iec61850/iec61850_model.h>

extern char *ini_file_path;                  // 当前路径
#define MQTT_CMD_61850_INIT           101     // 初始化
#define MQTT_CMD_61850_UPDATE         102     // Update

#define MQTT_CMD_61850_INIT_REQUEST   111     // 请求初始化
#define MQTT_CMD_61850_SWITCH         120     // 开关控制

// 函数接口
void IEC61850OnMqttMsg(int cmd, char *msg, int len);

void IEC61850RequestCfg();

void IEC61850Start();

void IEC61850Cleanup();

void IEC61850OnTimer();

//********************************
#ifdef __cplusplus
}
#endif

#endif //RY_ICE61850_H