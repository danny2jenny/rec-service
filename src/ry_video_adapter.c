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
#include "ry_video_adapter.h"
#include "ry_msg.h"

// 配置文件的风格符号
char rec_delim[] = ";";
char field_delim[] = ",";

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
                nvr_interface->nvr_free = (NVR_ADP_FREE) dlsym(hDll, "nvr_free");
            }

        } else {
            // DLL 已经被加载
        }

    }

    // 对 ry_nvr_records 进行遍历，登录到相应的NVR
    for (nvr_record = ry_nvr_records; nvr_record != NULL; nvr_record = nvr_record->hh.next) {
        HASH_FIND_INT(ry_nvr_interfaces, &(nvr_record->type), nvr_interface);
        if ((nvr_interface != NULL) && (nvr_interface->dll != NULL)) {
            if (nvr_interface->nvr_login != NULL) {
                session = nvr_interface->nvr_login(nvr_record->ip,
                                                   nvr_record->port,
                                                   nvr_record->username,
                                                   nvr_record->password);
                if (session >= 0) {
                    nvr_record->session = session;
                } else {
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
 * 读取配置的字符串，字符串以以下的方式
 * ChannelId,IP,Port,Username,Password,Type;
 * @param cfg
 * @return
 */
int parse_config(char *cfg) {

    // 清理当前的所有接口
    rest_adapters();

    // 用于临时存放readord和field的指针
    char *p_record;
    char *p_field;

    RY_NVR_INTERFACE *nvr_dll;

    RY_NVR_RECORD *nvr_rec;

    p_record = strtok(cfg, rec_delim);

    // 记录处理，添加NVR
    while (p_record != NULL) {

        int skipe_len = strlen(p_record) + 1;

        // 字段处理
        p_field = strtok(p_record, field_delim);

        // 生成一个配置记录
        nvr_rec = malloc(sizeof(RY_NVR_RECORD));         // 分配Hash表项目
        int field_index = 0;
        while (p_field != NULL) {
            // 每一个字段
            switch (field_index) {
                case 0: // id
                    nvr_rec->id = atoi(p_field);
                    break;
                case 1: // ip
                    strcpy(nvr_rec->ip, p_field);
                    break;
                case 2: // port
                    nvr_rec->port = atoi(p_field);
                    break;
                case 3: // username
                    strcpy(nvr_rec->username, p_field);
                    break;
                case 4: // password
                    strcpy(nvr_rec->password, p_field);
                    break;
                case 5: // type
                    nvr_rec->type = atoi(p_field);
                    break;
            }
            p_field = strtok(NULL, field_delim);
            field_index++;
        };

        HASH_ADD_INT(ry_nvr_records, id, nvr_rec);                 // 加入到Hash


        // 添加对应接口，首先判断是否存在
        HASH_FIND_INT(ry_nvr_interfaces, &(nvr_rec->type), nvr_dll);
        if (nvr_dll == NULL) {
            nvr_dll = malloc(sizeof(RY_NVR_INTERFACE));
            nvr_dll->id = nvr_rec->type;
            HASH_ADD_INT(ry_nvr_interfaces, id, nvr_dll);
        }

        // 查找下一条记录
        p_record = p_record + skipe_len;
        p_record = strtok(p_record, rec_delim);
    }

    // 加载动态链接库
    load_share_libs();
}

/**
 * 收到NVR的消息
 * @param nvr
 * @param event
 * @param data
 * @return
 */
int nvr_on_message(int nvr, int event, void *data) {

}

/**
 * 收到 MQTT消息
 * @param msg
 * @param len
 */
void video_on_mqtt_message(char *msg, int len) {
    // 消息头解析
    char *p1 = strchr(msg, '<');
    char *p2 = strchr(msg, '>');

    if (p1 == NULL || p2 == NULL) {
        return;
    }
    int cmd = atoi(p1 + 1);
    char *body = p2 + 1;

    // 用于解析参数的变量
    char *p_field;
    int i = 0;

    // PTZ参数
    int ptz_cmd = 0;        // PTZ 命令
    int nvr_id = 0;         // NVR id
    int nvr_node = 0;       // session 的通道号
    int ptz_parm = 0;       // PTZ 参数

    // 消息体解析
    switch (cmd) {

        case MQTT_CMD_VIDEO_INIT:
            video_adp_state = 1;
            // 初始化adapter
            parse_config(body);
            break;
        case MQTT_CMD_VIDEO_PTZ:
            // 云台控制
            p_field = strtok(body, field_delim);

            while (p_field != NULL) {
                switch (i) {
                    case 0:
                        // PTZ 命令
                        ptz_cmd = atoi(p_field);
                        break;
                    case 1:
                        // NVR id
                        nvr_id = atoi(p_field);
                        break;
                    case 2:
                        nvr_node = atoi(p_field);
                        break;
                    case 3:
                        // 参数
                        ptz_parm = atoi(p_field);
                        break;
                }

                p_field = strtok(NULL, field_delim);
                i++;
            }
            nvr_ptz_ctl(ptz_cmd, nvr_id, nvr_node, ptz_parm);
            break;// 云台控制
    }
}

/**
 * 定时检查
 * 多线程访问
 */
void ry_vide_ontime() {

    // 是否已经初始化，如果没有初始化，需要向MC发送相应的消息
    if (!video_adp_state) {
        // 发送配置请求，等待配置命令
        mqtt_send_to_mc(MQTT_CMD_INIT_REQUEST, NULL, 0);
    } else {
        // todo 检查登录状态

    }

}
