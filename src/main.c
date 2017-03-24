/**
 * 1、维护一个libuv的event loop 供其他的模块调用
 * 2、管理程序的生命周期
 *
 * https://github.com/luohaha/Chinese-uvbook
 * http://luohaha.github.io/Chinese-uvbook/
 */
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <conio.h>
#include <uv/uv.h>
#include "main.h"
#include "ry_msg_sub.h"
#include <mosquitto.h>


//-------------------全局变量---------------------------
uv_loop_t *ry_loop; // livuv 事件循环
char *msg_srv_url;       // 服务URL
//----------------------------------------------------


/**
 * 接收系统的信号，用于终止消息循环
 * @param signalId
 */
void sigint_handler(int signalId) {
    uv_stop(ry_loop);
}

/**
 * 定时事件，在这里循环执行各个功能模块的定时功能
 */
static void on_timer(uv_timer_t *handle) {
    //printf("this is on time--------------\n");

    char *topic = "sensor";
    extern struct mosquitto *mosq;
    mosquitto_publish(mosq, NULL, topic, 6, topic, 0, false);
}

//主函数入口
int main(int argc, char *argv[]) {
    // ---------------------设置运行参数-----------------------------
//    if (argc < 2) {
//        printf("%s\n", "you shoud define ip and port in commanline!");
//        getch();
//        return 0;
//    }
//
//    msg_srv_url = argv[1];

    // 系统信号
    signal(SIGINT, sigint_handler);

    // 初始化消息循环
    ry_loop = uv_default_loop();

    // 初始化相关的消息处理

    uv_timer_t timer_req;
    uv_timer_init(ry_loop, &timer_req);

    uv_timer_start(&timer_req, on_timer, 1000, 1000);


    // 开启订阅
    ry_msg_sub_init(argc, argv);

    // 运行消息循环
    return uv_run(ry_loop, UV_RUN_DEFAULT);

}
