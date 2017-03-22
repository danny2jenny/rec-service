/*
所有的NVR的通用接口
*/

#ifndef RY_VIDEO_ADAPTER_H
#define RY_VIDEO_ADAPTER_H
#ifdef __cplusplus
extern "C" {
#endif

#include <uv/uv.h>
#include <ut/uthash.h>

// 命令常量
#define TCP_CMD_CFG 1;   // 发送配置
#define TCP_CMD_PTZ = 2; // 云台控制

// 标准云台操作命令
#define SET_PRESET 1;  //设置
#define CLE_PRESET 2;  //清除
#define GOTO_PRESET 3; //调用


// NVR 接口回调函数
typedef int (*NVR_ADP_CALLBACK)(int nvr, int event, void *data);

// NVR Adapter DLL 的接口函数
typedef int (*NVR_ADP_LOG_IN)(char *ip, int port, char *username, char *password);       // 登录DVR，返回Session
typedef int (*NVR_ADP_PTZ)(int nvr, int cmd, int ptz);                                   // PTZ控制
typedef int (*NVR_ADP_CALLBACK_REG)(NVR_ADP_CALLBACK);                                   // 注册回调接口


// NVR 配置结构
typedef struct {
    int id;                 // NVRid/channelId
    char ip[20];            // IP
    int port;               // Port
    char username[20];      // Username
    char password[20];      // Password
    int type;               // Channel 类型
    HANDLE session;         // NVR/Channel 对应的session，登录后才有，HK中叫做Userid
    UT_hash_handle hh;      // Hash控制域
} RY_NVR_RECORD;

// NVR 接口的结构体
typedef struct {
    int id;                                     // 接口的类型标识对应RY_NVR_RECORD的type
    HANDLE dll;                                 // DLL 的Handle
    NVR_ADP_LOG_IN nvr_login;                   // NVR 登录
    NVR_ADP_PTZ nvr_ptz;                        // PTZ 控制
    NVR_ADP_CALLBACK_REG nvr_callback_reg;      // 注册回调
    UT_hash_handle hh;                          // Hash控制域
} RY_NVR_INTERFACE;

// 对外接口
int parse_config(char *cfg);

void client_on_message(char *buf, int len);

#ifdef __cplusplus
}
#endif
#endif