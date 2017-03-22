/**
 *
 * 海康NVR的操作接口
 */

#include <hk/HCNetSDK.h>
#include <stdio.h>


// 初始化
extern "C" {

void device_init()
{
    //  初始化
    NET_DVR_Init();
    //设置连接时间与重连时间
    NET_DVR_SetConnectTime(2000, 1);
    NET_DVR_SetReconnect(10000, true);

    //---------------------------------------
    //  注册设备
    LONG lUserID;
    // NET_DVR_DEVICEINFO_V30 struDeviceInfo;
    // lUserID = NET_DVR_Login_V30("172.6.22.165", 8000, "admin", "12345", &struDeviceInfo);
    // if (lUserID < 0)
    // {
    //     printf("Login error, %d\n", NET_DVR_GetLastError());
    //     NET_DVR_Cleanup();
    // }

    printf("HK DVR INIT: %d\n", 0); //模拟通道个数
}

// 注册回调函数
/*
    NET_DVR_SetDVRMessage
    NET_DVR_SetExceptionCallBack
    这两个函数用于注册不同类型的回调
    */

// 设置PTZ
int set_ptz(LONG channel, DWORD dwPresetIndex)
{
    return 0;
}

// 清理
void device_cleanup()
{
    NET_DVR_Cleanup();
}
}