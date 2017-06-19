//
// 
//

#ifndef RY_SERVICE_61850_H
#define RY_SERVICE_61850_H

#ifdef __cplusplus
extern "C" {
#endif
//********************************

#include <ut/uthash.h>
#include <iec61850/iec61850_model.h>

#define MQTT_CMD_61850_INIT           101     // 初始化
#define MQTT_CMD_61850_UPDATE         102     // Update

#define MQTT_CMD_61850_INIT_REQUEST   111     // 请求初始化


// 61850 逻辑节点
typedef struct {
    int id;                                     // device id
    int type;                                   // 节点的类型
    LogicalNode *ln;                            // 61850 逻辑节点
    UT_hash_handle hh;                          // Hash控制域
} RY_61850_LN;

// 函数接口
void iec61850_on_mqtt_message(int cmd, char *msg, int len);
void ry_61850_request_config();
void iec61850_start();
void iec61850_cleanup();
void ry_61850_ontime();

//********************************
#ifdef __cplusplus
}
#endif

#endif //RY_SERVICE_61850_H