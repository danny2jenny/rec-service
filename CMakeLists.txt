cmake_minimum_required(VERSION 3.6)
project(RY_Service)

SET(CMAKE_GENERATOR “MSYS Makefiles”)
set(CMAKE_C_STANDARD 99)
SET(CMAKE_C_FLAGS_DEBUG "-D_DEBUG")

# 设置编译后文件的输出位置
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 工程中头文件存放位置
include_directories (
        # 包含该工程的头文件
        "${PROJECT_SOURCE_DIR}/include"
        "${PROJECT_SOURCE_DIR}/src"
)

# 静态库文件存放位置
link_directories(
        "${PROJECT_SOURCE_DIR}/lib"
)

# 需要连接的静态库文件
link_libraries(
        "uv"
        "psapi"
        "ws2_32"
        "userenv"
        "iphlpapi"
        "HCNetSDK"
        "paho-mqtt3a"
)

set(SOURCE_FILES src/main.c src/ry_msg_sub.c)

add_executable(RY_Service ${SOURCE_FILES})