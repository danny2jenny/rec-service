/*
 * 所有的NVR的通用接口
 *
 */

#ifndef RY_VIDEO_ADAPTER_H
#define RY_VIDEO_ADAPTER_H
#ifdef __cplusplus
extern "C" {
#endif

#include <ut/uthash.h>

// ************************ 命令常量 ***************************

// 标准云台操作命令
#define PTZ_SET_PRESET 1    //设置
#define PTZ_CLE_PRESET 2    //清除
#define PTZ_GOTO_PRESET 3   //调用


// ************************ 函数指针 ***************************
// NVR 接口回调函数
typedef int (*NVR_ADP_CALLBACK)(int nvr, int event, void *data);

// NVR Adapter DLL 的接口函数
typedef int (*NVR_ADP_LOG_IN)(char *ip, int port, char *username, char *password);       // 登录DVR，返回Session
typedef int (*NVR_ADP_PTZ)(int nvr, int cmd, int ptz);                                   // PTZ控制
typedef int (*NVR_ADP_CALLBACK_REG)(NVR_ADP_CALLBACK fun);                               // 注册回调接口
typedef int (*NVR_ADP_FREE)();                                                           // 释放资源


// **************************** hashmap **************************

// NVR 配置结构
typedef struct {
    int id;                 // NVRid/channelId
    char ip[20];            // IP
    int port;               // Port
    char username[20];      // Username
    char password[20];      // Password
    int type;               // Channel 类型
    int session;            // NVR/Channel 对应的session，登录后才有，HK中叫做Userid
    UT_hash_handle hh;      // Hash控制域
} RY_NVR_RECORD;

// NVR 接口的结构体
typedef struct {
    int id;                                     // 接口的类型标识对应RY_NVR_RECORD的type
    void *dll;                                  // DLL 的Handle
    NVR_ADP_LOG_IN nvr_login;                   // NVR 登录
    NVR_ADP_PTZ nvr_ptz;                        // PTZ 控制
    NVR_ADP_CALLBACK_REG nvr_callback_reg;      // 注册回调
    NVR_ADP_FREE nvr_adp_free;                  // 释放资源
    UT_hash_handle hh;                          // Hash控制域
} RY_NVR_INTERFACE;

// *********************** 对外接口 ****************************
/**
 * 定时调用
 */
void ry_vide_ontime();

/**
 * 收到MQTT消息
 * @param msg
 * @param len
 */
void video_on_mqtt_message(char *msg, int len);

#ifdef __cplusplus
}
#endif
#endif