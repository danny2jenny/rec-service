/*
大华NVR的操作接口
*/

#include <stdio.h>

// 初始化
extern "C" {

void device_init()
{
    printf("DH DVR INIT: %d\n", 111); //模拟通道个数
}

// 注册回调函数
/*
    NET_DVR_SetDVRMessage
    NET_DVR_SetExceptionCallBack
    这两个函数用于注册不同类型的回调
    */

// 设置PTZ
int set_ptz(int channel, int dwPresetIndex)
{
}

// 清理
void device_cleanup()
{
}
}