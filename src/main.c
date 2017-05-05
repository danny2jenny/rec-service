/**
 * 1、维护一个libuv的event loop 供其他的模块调用
 * 2、管理程序的生命周期
 *
 * https://github.com/luohaha/Chinese-uvbook
 * http://luohaha.github.io/Chinese-uvbook/
 */
#include <uv.h>

#include "ry_msg.h"
#include "ry_video_adapter.h"


//-------------------全局变量---------------------------
uv_loop_t *ry_loop;   // livuv 事件循环

char *mqtt_ip;       // 服务URL
int mqtt_port;       // 服务端口
//----------------------------------------------------

// 定时器
uv_timer_t timer_req;

/**
 * 接收系统的信号，用于终止消息循环
 * @param signalId
 */
void sigint_handler(int signalId) {
    // 清理 MQTT 通讯
    mqtt_cleanup();

    // 清理 video adapter
    clear_video_adapters();

    // 停止消息循环
    uv_stop(ry_loop);
}

/**
 * 定时事件，在这里循环执行各个功能模块的定时功能
 */
static void on_timer(uv_timer_t *handle) {
    ry_vide_ontime();           // video adapter 定时任务
}

/**
 * 开始定时器
 */
void timer_start() {
// start after 1 secends, repeat every 2 seconds
    uv_timer_start(&timer_req, on_timer, 1000, 2000);
}

/**
 * 停止定时器
 */
void timer_stop() {
    uv_timer_stop(&timer_req);
}

//主函数入口
int main(int argc, char *argv[]) {
    // ---------------------设置运行参数-----------------------------
    if (argc < 3) {
        printf("%s\n", "you shoud define ip and port in commanline!");
        return 0;
    }

    mqtt_ip = argv[1];
    mqtt_port = atoi(argv[2]);

    // 系统信号
    signal(SIGINT, sigint_handler);

    // 初始化消息循环
    ry_loop = uv_default_loop();

    // 初始化相关的消息处理

    // 定时器
    uv_timer_init(ry_loop, &timer_req);
    timer_start();

    // 开启订阅
    ry_msg_init(mqtt_ip, mqtt_port);

    // 运行消息循环
    uv_run(ry_loop, UV_RUN_DEFAULT);

}
