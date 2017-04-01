/**
 *
 * 海康NVR的操作接口
 */

#include <hk/HCNetSDK.h>
#include <cstdio>
#include "ry_video_adapter.h"


// 初始化
extern "C" {

// 回调函数
NVR_ADP_CALLBACK nvr_adp_callback;


/**
 * 登录
 * @param ip
 * @param port
 * @param username
 * @param password
 * @return
 */
int nvr_adp_log_in(char *ip, int port, char *username, char *password) {
    //  初始化
    NET_DVR_Init();
    //设置连接时间与重连时间
    NET_DVR_SetConnectTime(2000, 1);
    NET_DVR_SetReconnect(10000, true);

    //---------------------------------------
    //  注册设备
    LONG lUserID;
    NET_DVR_DEVICEINFO_V30 struDeviceInfo;
    lUserID = NET_DVR_Login_V30(ip, port, username, password, &struDeviceInfo);

    // 设置相应的回调
    // NET_DVR_SetDVRMessage NET_DVR_SetExceptionCallBack_V30
    // todo：实现事件的监听
    if (lUserID >= 0) {

    }
    return lUserID;

}

/**
 * PTZ 控制
 * @param session
 * @param cmd
 * @param ptz
 * @return
 */
int nvr_adp_ptz(int session, int cmd, int cha, int ptz) {

    int rst;
    switch (cmd) {
        case PTZ_SET_PRESET:
            rst = NET_DVR_PTZPreset_Other(session, cha, SET_PRESET, ptz);
            break;
        case PTZ_CLE_PRESET:
            rst = NET_DVR_PTZPreset_Other(session, cha, CLE_PRESET, ptz);
            break;
        case PTZ_GOTO_PRESET:
            rst = NET_DVR_PTZPreset_Other(session, cha, GOTO_PRESET, ptz);
            break;
    }

    return rst;
}

/**
 * 注册回调函数
 * @param fun
 * @return
 */
int nvr_adp_callback_reg(NVR_ADP_CALLBACK fun) {
    nvr_adp_callback = fun;
    return 0;
}

/**
 * 资源释放
 */
int nvr_adp_free() {
    NET_DVR_Cleanup();
    return 0;
}

}
