/**
 * 用于管理不同的NVR的接口
 * NVR配置信息, 对应数据库的 Channel 表
 * ChannelId         IP      Port        Username           Password         Type
 *
 * 从MC读取的NVR配置Hash RY_NVR_RECORD
 * NVR 的操作接口Hash RY_NVR_INTERFACE
 */

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

#include "ry_video_adapter.h"

// 配置文件的风格符号
char rec_delim[] = ";";
char field_delim[] = ",";

// nvr配置的HASH
RY_NVR_RECORD *ry_nvr_records = NULL;
// nvr驱动（动态链接库）、接口的对象
RY_NVR_INTERFACE *ry_nvr_interfaces = NULL;

// 根据类型，加载动态链接库
int load_share_libs() {
    // 遍历，加载动态链接库
    RY_NVR_INTERFACE *nvr_interface;

    for (nvr_interface = ry_nvr_interfaces; nvr_interface != NULL; nvr_interface = nvr_interface->hh.next) {
        int type = nvr_interface->id;
        char filename[40] = "libnvr";
        itoa(type, &filename[6], 10);
        strcpy(&filename[strlen(filename)], ".dll");
        HINSTANCE hDll = LoadLibrary(filename);
        // 添加DLL接口函数的指针
        if (hDll != NULL) {
            nvr_interface->dll = hDll;
            nvr_interface->nvr_login = (NVR_ADP_LOG_IN) GetProcAddress(hDll, "nvr_login");
            nvr_interface->nvr_ptz = (NVR_ADP_PTZ) GetProcAddress(hDll, "nvr_ptz");
            nvr_interface->nvr_callback_reg = (NVR_ADP_CALLBACK_REG) GetProcAddress(hDll, "nvr_callback_reg");
        }
    }
}

/*
读取配置的字符串，字符串以以下的方式
ChannelId,IP,Port,Username,Password,Type;
*/
int parse_config(char *cfg) {
    char *p_record;
    char *p_field;
    p_record = strtok(cfg, rec_delim);

    // 记录处理
    while (p_record != NULL) {
        // 字段处理
        int skipe_len = strlen(p_record) + 1;
        p_field = strtok(p_record, field_delim);

        // 生成一个配置记录
        RY_NVR_RECORD *rec = malloc(sizeof(RY_NVR_RECORD));
        int field_index = 0;
        while (p_field != NULL) {
            // 每一个字段
            switch (field_index) {
                case 0: // id
                    rec->id = atoi(p_field);
                    break;
                case 1: // ip
                    strcpy(rec->ip, p_field);
                    break;
                case 2: // port
                    rec->port = atoi(p_field);
                    break;
                case 3: // username
                    strcpy(rec->username, p_field);
                    break;
                case 4: // password
                    strcpy(rec->password, p_field);
                    break;
                case 5: // type
                    rec->type = atoi(p_field);
                    break;
            }
            HASH_ADD_INT(ry_nvr_records, id, rec);

            p_field = strtok(NULL, field_delim);
            field_index++;
        };

        // 添加对应接口，首先判断是否存在
        RY_NVR_INTERFACE *nvr_dll;
        HASH_FIND_INT(ry_nvr_interfaces, &(rec->type), nvr_dll);
        if (nvr_dll == NULL) {
            nvr_dll = malloc(sizeof(RY_NVR_INTERFACE));
            nvr_dll->id = rec->type;
            HASH_ADD_INT(ry_nvr_interfaces, id, nvr_dll);
        }

        // 查找下一条记录
        p_record = p_record + skipe_len;
        p_record = strtok(p_record, rec_delim);
    }
    load_share_libs();
}

// 收到消息
void client_on_message(char *buf, int len) {
    printf("%s\n", buf);
}
