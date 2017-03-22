/*******************************************************************************
 * MQTT 的消息订阅
 *******************************************************************************/

#include "stdio.h"
#include "stdlib.h"
#include "mqtt/MQTTAsync.h"

#if !defined(WIN32)
#include <unistd.h>
#else

#include <windows.h>
#include <mqtt/MQTTAsync.h>

#endif

#define CLIENTID    "RY_SERVICE"
#define TOPIC       "sensor"
#define QOS         1

volatile MQTTAsync_token deliveredtoken;

int disc_finished = 0;
int subscribed = 0;
int finished = 0;

/**
 *  连接丢失
 * @param context
 * @param cause
 */
void connlost(void *context, char *cause) {
    MQTTAsync client = (MQTTAsync) context;
    MQTTAsync_connectOptions conn_opts = MQTTAsync_connectOptions_initializer;
    int rc;

    printf("\nConnection lost\n");
    printf("     cause: %s\n", cause);

    printf("Reconnecting\n");
    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;
    if ((rc = MQTTAsync_connect(client, &conn_opts)) != MQTTASYNC_SUCCESS) {
        printf("Failed to start connect, return code %d\n", rc);
        finished = 1;
    }
}

/**
 * 收到消息
 * @param context
 * @param topicName
 * @param topicLen
 * @param message
 * @return
 */
int msgarrvd(void *context, char *topicName, int topicLen, MQTTAsync_message *message) {
    int i;
    char *payloadptr;

    printf("Message arrived\n");
    printf("     topic: %s\n", topicName);
    printf("   message: ");

    payloadptr = message->payload;
    for (i = 0; i < message->payloadlen; i++) {
        putchar(*payloadptr++);
    }
    putchar('\n');
    MQTTAsync_freeMessage(&message);
    MQTTAsync_free(topicName);
    return 1;
}

/**
 * 断开连接发生的事件
 * @param context
 * @param response
 */
void onDisconnect(void *context, MQTTAsync_successData *response) {
    printf("Successful disconnection\n");
    disc_finished = 1;
}

/**
 * 订阅成功
 * @param context
 * @param response
 */
void onSubscribe(void *context, MQTTAsync_successData *response) {
    printf("Subscribe succeeded\n");
    subscribed = 1;
}

/**
 * 订阅失败
 * @param context
 * @param response
 */
void onSubscribeFailure(void *context, MQTTAsync_failureData *response) {
    printf("Subscribe failed, rc %d\n", response ? response->code : 0);
    finished = 1;
}

/**
 * 连接失败
 * @param context
 * @param response
 */
void onConnectFailure(void *context, MQTTAsync_failureData *response) {
    printf("Connect failed, rc %d\n", response ? response->code : 0);
    finished = 1;
}

/**
 * 连接后的事件
 * @param context
 * @param response
 */
void onConnect(void *context, MQTTAsync_successData *response) {
    MQTTAsync client = (MQTTAsync) context;
    MQTTAsync_responseOptions opts = MQTTAsync_responseOptions_initializer;
    MQTTAsync_message pubmsg = MQTTAsync_message_initializer;
    int rc;

    printf("Successful connection\n");

    printf("Subscribing to topic %s\nfor client %s using QoS%d\n\n"
                   "Press Q<Enter> to quit\n\n", TOPIC, CLIENTID, QOS);
    opts.onSuccess = onSubscribe;
    opts.onFailure = onSubscribeFailure;
    opts.context = client;

    deliveredtoken = 0;

    if ((rc = MQTTAsync_subscribe(client, TOPIC, QOS, &opts)) != MQTTASYNC_SUCCESS) {
        printf("Failed to start subscribe, return code %d\n", rc);
        //exit(EXIT_FAILURE);
    }
}

/**
 * 初始化消息订阅
 * @param ip
 * @param port
 * @return
 */
extern char *msg_srv_url;                   // 服务URL

int ry_msg_sub_init() {

    MQTTAsync client;                                                                       // 客户端
    MQTTAsync_connectOptions conn_opts = MQTTAsync_connectOptions_initializer;              // 连接属性
    MQTTAsync_disconnectOptions disc_opts = MQTTAsync_disconnectOptions_initializer;        // 断开属性
    MQTTAsync_message pubmsg = MQTTAsync_message_initializer;                               // 订阅消息的结构
    MQTTAsync_token token;                                                                  // 消息令牌

    int rc;                                                                                 // 连接后返回的错误代码

    // 连接服务器 异步操作
    MQTTAsync_create(&client, msg_srv_url, CLIENTID, MQTTCLIENT_PERSISTENCE_NONE, NULL);

    MQTTAsync_setCallbacks(client, NULL, connlost, msgarrvd, NULL);

    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;
    conn_opts.onSuccess = onConnect;
    conn_opts.onFailure = onConnectFailure;
    conn_opts.context = client;
    if ((rc = MQTTAsync_connect(client, &conn_opts)) != MQTTASYNC_SUCCESS) {
        printf("Failed to start connect, return code %d\n", rc);
        //exit(EXIT_FAILURE);
    }


    disc_opts.onSuccess = onDisconnect;

    return rc;
}

void ry_msg_sub_free() {
    // MQTTAsync_destroy(&client);
}
