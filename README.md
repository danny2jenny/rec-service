# 简介

该服务与NVR、DVR进行通信，主要实现前端摄像机的预置位的调用，在告警时，可以控制摄像头的转动。

# 设计

* 可以兼容不同的NVR、DVR
* 独立服务，与REC通过HTTP服务器进行交互

可以采用libuv进行简单的TCP连接，和服务器进行通信

# 过程

* 通过 HTTP 接收 REC 发来的NVR、DVR配置
* 为每个NVR维护一个对象，实现与NVR的通信
* 接收 REC 发来的预置位调用，并通过与相应NVR的连接，实现对前端摄像机的控制

# 相关工具

libuv 电子书
http://luohaha.github.io/Chinese-uvbook/source/introduction.html

HttpServer libmicrohttpd

HttpRequrest libcurl

HashTable https://github.com/troydhanson/uthash   https://troydhanson.github.io/uthash/

#使用 MQTT 作为传输协议

服务器：https://mosquitto.org/
mosquitto_sub -v -t sensor 
mosquitto_pub -t sensor -m 13 



## mqtt 环境

服务器采用mosquitto

编译环境：libmosquitto-dev	libuv1-dev

# 对比
https://www.predic8.com/activemq-hornetq-rabbitmq-apollo-qpid-comparison.htm

# MQTT 相关的资源

Spring 集成 http://docs.spring.io/spring-integration/reference/html/mqtt.html

相关的软件：https://github.com/mqtt/mqtt.github.io/wiki/software?id=software

一个嵌入式的服务：https://github.com/andsel/moquette

# MQTT 测试服务

iot.eclipse.org 1883

# Linux 服务

[Unit]
Description=MQTT Service
After=network.target

[Service]
User=rytec
Restart=always
Type=forking
ExecStart=/home/rytec/data/moquette/bin/moquette.sh

[Install]
WantedBy=multi-user.targe

连接到 /etc/systemd/system/mu  mlti-user.target.wants

# 依赖包
build-essential
libuv1-dev
libmosquitto-dev

# Json 库

https://github.com/DaveGamble/cJSON
https://github.com/kgabis/parson
https://github.com/akheron/jansson      // 文档比较丰富
https://github.com/zserge/jsmn

https://github.com/cesanta/frozen
https://docs.cesanta.com/frozen/master/     // 文档也比较丰富

# Goos 报告的解决

原因分析：没有特权，如果 sudo 运行就没有问题。

另外，需要制定用那个网卡，具体请参考：servr_example_goose.c 这个例子。