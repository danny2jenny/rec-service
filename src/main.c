/**
 * 1、维护一个libuv的event loop 供其他的模块调用
 * 2、管理程序的生命周期
 *
 * https://github.com/luohaha/Chinese-uvbook
 * http://luohaha.github.io/Chinese-uvbook/
 */
#include <uv.h>
#include "ry_mqtt.h"
#include "ry_nvr_mgr.h"
#include "ry_iec61850.h"
#include "ini.h"


//-------------------全局变量---------------------------
uv_loop_t *ry_loop;             // livuv 事件循环

char mqtt_host[100];            // 服务URL
int mqtt_port;                  // 服务端口
uv_timer_t timer_req;           // 定时器

char * ini_file_path;       // 当前路径
//----------------------------------------------------

/**
 * 接收系统的信号，用于终止消息循环
 * @param signalId
 */
void SigintHandler(int signalId) {
    MqttClean();                    // 清理 MQTT 通讯
    NvrClearAdps();                 // 清理 video adapter
    IEC61850Cleanup();              // 清理 61850
    uv_stop(ry_loop);               // 停止消息循环
}

/**
 * 定时事件，在这里循环执行各个功能模块的定时功能
 */
static void OnTimer(uv_timer_t *handle) {
    //NvrOnTimer();               // video adapter 定时任务
    IEC61850OnTimer();              // 61850 定时任务
}

/**
 * 开始定时器
 */
void TimerStart() {
    // start after 1 secends, repeat every 2 seconds
    uv_timer_start(&timer_req, OnTimer, 1000, 2000);
}

/**
 * 停止定时器
 */
void TimerStop() {
    uv_timer_stop(&timer_req);
}

//主函数入口
int main(int argc, char *argv[]) {

    ini_file_path = argv[1];

    // ---------------------设置运行参数-----------------------------
    ini_t *config = ini_load(ini_file_path);

    ini_sget(config, "mqtt", "host", "%s", mqtt_host);
    ini_sget(config, "mqtt", "port", "%d", &mqtt_port);

    ini_free(config);
    // ------------------------------------------------------------


    signal(SIGINT, SigintHandler);              // 系统信号
    ry_loop = uv_default_loop();                // 初始化消息循环


    uv_timer_init(ry_loop, &timer_req);         // 定时器
    TimerStart();

    MqttInit(mqtt_host, mqtt_port);             // MQTT 消息客户端链接  todo 不应该这样写，应该放在定时任务中。强迫症!!!
    uv_run(ry_loop, UV_RUN_DEFAULT);            // 运行消息循环
}
