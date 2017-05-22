/**
 * 用于管理不同的NVR的接口
 * NVR配置信息, 对应数据库的 Channel 表
 * ChannelId         IP      Port        Username           Password         Type
 *
 * 从MC读取的NVR配置Hash RY_NVR_RECORD
 * NVR 的操作接口Hash RY_NVR_INTERFACE
 *
 * 通讯格式：
 * <cmd>payload
 *
 * cmd:数值
 * payload 数据区
 *
 * 数据分割：',' 字段分割，';' 记录分割
 */

#include <stdio.h>
#include <dlfcn.h>
#include <parson/parson.h>
#include "ry_video_adapter.h"
#include "ry_msg.h"
#include "main.h"
#include "config.h"

// 超前引用
void ry_video_online(int nvr);


volatile int video_adp_state = 0;                 // video 接口初始化状态

// nvr配置的HASH
RY_NVR_RECORD *ry_nvr_records = NULL;
// nvr驱动（动态链接库）、接口的对象
RY_NVR_INTERFACE *ry_nvr_interfaces = NULL;


/**
 * PTZ控制
 * @param cmd
 * @param nvr
 * @param node
 * @param parm
 * @return
 */
void nvr_ptz_ctl(int cmd, int nvr, int node, int parm) {
    RY_NVR_RECORD *nvr_record;
    RY_NVR_INTERFACE *nvr_interface;
    HASH_FIND_INT(ry_nvr_records, &nvr, nvr_record);

    if (nvr_record->session < 0) {
        // todo: 错误消息
        return;
    }

    if (nvr_record != NULL) {
        HASH_FIND_INT(ry_nvr_interfaces, &(nvr_record->type), nvr_interface);
        if ((nvr_interface->dll != NULL) && (nvr_interface->nvr_ptz != NULL)) {
            nvr_interface->nvr_ptz(nvr_record->session, cmd, node, parm);
        }
    }
}

/**
 * 检查并登录所有的NVR
 */
void nvr_login() {
    // 遍历，加载动态链接库
    RY_NVR_INTERFACE *nvr_interface;            // 当前遍历中的一个 interface
    RY_NVR_RECORD *nvr_record;                  // 当前遍历中的一个 record

    int session = 0;                            // 登录后的session

    // 遍历所有的ＮＶＲ
    for (nvr_record = ry_nvr_records; nvr_record != NULL; nvr_record = nvr_record->hh.next) {

        // 找到NVR对应的DLL实现的Interface
        HASH_FIND_INT(ry_nvr_interfaces, &(nvr_record->type), nvr_interface);
        // 判断interface和DLL是否实现
        if ((nvr_interface != NULL) && (nvr_interface->dll != NULL)) {

            // 如果登录，就退出
            if (nvr_record->session > 0) {
                continue;
            }

            if (nvr_interface->nvr_login != NULL) {
                session = nvr_interface->nvr_login(nvr_record->ip,
                                                   nvr_record->port,
                                                   nvr_record->username,
                                                   nvr_record->password);
                if (session > 0) {
                    // 登录成功
                    nvr_record->session = session;
                    ry_video_online(nvr_record->id);
                } else {
                    // todo:登录失败，应该向外发送消息
                    session = 0;
                }

                printf("Session = %d\n", session);
            }

            // 更新Session
            nvr_record->session = session;
        }
    }
}


/**
 * 根据配置文件，装载动态链接库
 * @return
 */
int load_share_libs() {
    // 遍历，加载动态链接库
    RY_NVR_INTERFACE *nvr_interface;            // 当前遍历中的一个 interface
    RY_NVR_RECORD *nvr_record;                  // 当前遍历中的一个 record

    int session = 0;                            // 登录后的session

    // 装载动态链接库
    // 对nvr_interface 进行遍历
    for (nvr_interface = ry_nvr_interfaces; nvr_interface != NULL; nvr_interface = nvr_interface->hh.next) {

        if (nvr_interface->dll == NULL) {
            // Dll 未被加载
            int type = nvr_interface->id;
            char filename[40] = "libnvr";
            sprintf(&filename[6], "%d", type);
            strcpy(&filename[strlen(filename)], ".so");
            void *hDll = dlopen(filename, RTLD_NOW);
            // 添加DLL接口函数的指针
            if (hDll != NULL) {
                nvr_interface->dll = hDll;
                nvr_interface->nvr_login = (NVR_ADP_LOG_IN) dlsym(hDll, "nvr_adp_log_in");
                nvr_interface->nvr_ptz = (NVR_ADP_PTZ) dlsym(hDll, "nvr_adp_ptz");
                nvr_interface->nvr_callback_reg = (NVR_ADP_CALLBACK_REG) dlsym(hDll, "nvr_adp_callback_reg");
                nvr_interface->nvr_free = (NVR_ADP_FREE) dlsym(hDll, "nvr_adp_free");

                // 注册回调函数
            }

        } else {
            // DLL 已经被加载
        }

    }
}

/**
 * 重置当前的NVR和Adapater
 * 1、关闭每个Adapter打开的NVR
 * 2、清理NVR的HASH列表
 */
void rest_adapters() {
    // 遍历，加载动态链接库
    RY_NVR_INTERFACE *nvr_interface;            // 当前遍历中的一个 interface
    RY_NVR_RECORD *nvr_record, *tmp;            // 当前遍历中的一个 record

    // 遍历 Video Interface
    for (nvr_interface = ry_nvr_interfaces; nvr_interface != NULL; nvr_interface = nvr_interface->hh.next) {
        // 释放相应的资源，但是不释放DLL
        nvr_interface->nvr_free();
    }

    // 遍历 NVR 记录，删除所有的
    HASH_ITER(hh, ry_nvr_records, nvr_record, tmp) {
        HASH_DEL(ry_nvr_records, nvr_record);
        free(nvr_record);
    }
}

/**
 * 清理所有的动态资源
 * 1、清理NVR的HASH
 * 2、关闭每个Adpater打开的NVR
 * 3、释放每个DLL
 */
void clear_video_adapters() {
    // 遍历，加载动态链接库
    RY_NVR_INTERFACE *nvr_interface, *tmp_interface;            // 当前遍历中的一个 interface
    RY_NVR_RECORD *nvr_record, *tmp_nvr;                        // 当前遍历中的一个 record

    // 遍历 Video Interface
    HASH_ITER(hh, ry_nvr_interfaces, nvr_interface, tmp_interface) {
        nvr_interface->nvr_free();
        // 关闭DLL
        if (nvr_interface->dll != NULL) {
            dlclose(nvr_interface->dll);
        }
        // 删除
        HASH_DEL(ry_nvr_interfaces, nvr_interface);
        free(nvr_interface);

    }

    // 遍历 NVR 记录，删除所有的
    HASH_ITER(hh, ry_nvr_records, nvr_record, tmp_nvr) {
        HASH_DEL(ry_nvr_records, nvr_record);
        free(nvr_record);
    }
}


/**
 * 收到NVR的消息
 * @param nvr
 * @param event
 * @param data
 * @return
 */
int nvr_on_message(int nvr, int channel, int event, void *data) {

}

/**
 * 解析配置文件
 * @param cfgStr
 */
void video_parse_config(char *cfgStr) {

    // 清理当前的所有接口
    rest_adapters();

    RY_NVR_INTERFACE *nvr_dll;

    RY_NVR_RECORD *nvr_rec;


    // *************json处理*******************
    JSON_Value *root_value;
    JSON_Object *root_object, *config_object;
    JSON_Array *json_array;

    root_value = json_parse_string(cfgStr);

    root_object = json_value_get_object(root_value);
    json_array = json_object_get_array(root_object, "payload");

    int i;
    for (i = 0; i < json_array_get_count(json_array); i++) {
        config_object = json_array_get_object(json_array, i);

        // 生成一个配置记录
        nvr_rec = malloc(sizeof(RY_NVR_RECORD));         // 分配Hash表项目
        nvr_rec->session = 0;

        nvr_rec->id = json_object_get_number(config_object, "id");
        strcpy(nvr_rec->ip, json_object_get_string(config_object, "ip"));
        nvr_rec->port = json_object_get_number(config_object, "port");
        strcpy(nvr_rec->username, json_object_get_string(config_object, "login"));
        strcpy(nvr_rec->password, json_object_get_string(config_object, "pass"));
        nvr_rec->type = json_object_get_number(config_object, "type");

        HASH_ADD_INT(ry_nvr_records, id, nvr_rec);                 // 加入到Hash


        // 添加对应接口，首先判断是否存在
        HASH_FIND_INT(ry_nvr_interfaces, &(nvr_rec->type), nvr_dll);
        if (nvr_dll == NULL) {
            nvr_dll = malloc(sizeof(RY_NVR_INTERFACE));
            nvr_dll->id = nvr_rec->type;
            HASH_ADD_INT(ry_nvr_interfaces, id, nvr_dll);
        }
    }

    /* cleanup code */
    json_value_free(root_value);

    // 加载动态链接库
    load_share_libs();

    // 对 ry_nvr_records 进行遍历，登录到相应的NVR
    nvr_login();
}

/**
 * 处理PTZ控制的json
 * @param jstr
 */
void video_parse_ptz(char *msg) {
    JSON_Value *root_value;
    JSON_Object *root_object, *payload_object;


    root_value = json_parse_string(msg);
    root_object = json_value_get_object(root_value);
    payload_object = json_object_get_object(root_object, "payload");

    int ptzCmd = json_object_get_number(payload_object, "ptzCmd");
    int nvr = json_object_get_number(payload_object, "nvr");
    int channel = json_object_get_number(payload_object, "channel");
    int ptz = json_object_get_number(payload_object, "ptz");

    nvr_ptz_ctl(PTZ_GOTO_PRESET, nvr, channel, ptz);
    /* cleanup code */
    json_value_free(root_value);
}

/**
 * 收到 MQTT消息
 * @param msg
 * @param len
 *
 * 消息格式: <cmd>+payload
 */
void video_on_mqtt_message(char *msg, int len) {

    JSON_Value *root_value;
    JSON_Object *root_object;


    root_value = json_parse_string(msg);

    root_object = json_value_get_object(root_value);

    int cmd = json_object_get_number(root_object, "cmd");

    switch (cmd) {
        case MQTT_CMD_VIDEO_INIT:
            video_adp_state = 1;
            video_parse_config(msg);
            break;
        case MQTT_CMD_VIDEO_PTZ:
            video_parse_ptz(msg);
            break;
    }

    /* cleanup code */
    json_value_free(root_value);
}

/**
 * 请求配置信息
 * 发送配置请求，等待配置命令
 */
void ry_video_request_config() {
    // 生成 Json 字符串
    JSON_Value *root_value = json_value_init_object();
    JSON_Object *root_object = json_value_get_object(root_value);
    char *serialized_string = NULL;

    json_object_set_number(root_object, "cmd", MQTT_CMD_INIT_REQUEST);
    json_object_set_null(root_object, "payload");
    serialized_string = json_serialize_to_string_pretty(root_value);

    // 发送请求
    mqtt_publish(RY_VIDEO_PUB_TOPIC, serialized_string, strlen(serialized_string));

    // 释放资源
    json_free_serialized_string(serialized_string);
    json_value_free(root_value);
}

/**
 * NVR 登录成功的通知
 * @param nvr
 */
void ry_video_online(int nvr) {
    // 生成 Json 字符串
    JSON_Value *root_value = json_value_init_object();
    JSON_Object *root_object = json_value_get_object(root_value);
    char *serialized_string = NULL;

    json_object_set_number(root_object, "cmd", MQTT_CMD_NVR_ONLINE);
    json_object_set_number(root_object, "channel", nvr);
    json_object_set_boolean(root_object, "online", 1);
    serialized_string = json_serialize_to_string_pretty(root_value);

    // 发送请求
    mqtt_publish(RY_VIDEO_PUB_TOPIC, serialized_string, strlen(serialized_string));

    // 释放资源
    json_free_serialized_string(serialized_string);
    json_value_free(root_value);
}

/**
 * 定时检查
 * 多线程访问
 */
void ry_vide_ontime() {

    // 是否已经初始化，如果没有初始化，需要向MC发送相应的消息
    if (!video_adp_state) {
        ry_video_request_config();
    } else {
        timer_stop();
        nvr_login();
        timer_start();
    }

}
