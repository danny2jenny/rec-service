cmake_minimum_required(VERSION 3.6)
project(RY_Service)

# windows的 msys 环境需要
SET(CMAKE_GENERATOR “MSYS Makefiles”)

#生成的代码可以用于GDB调试
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

# 设置动态链接库的搜索路径RPATH，可执行文件在linux下可以在当前路径搜索动态链接库
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-rpath,'$ORIGIN'")
SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-rpath,'$ORIGIN'")

# 设置编译后文件的输出位置
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 源文件的预编译选项
ADD_DEFINITIONS(-D_TEST)

# 工程中头文件存放位置
include_directories(
        "${PROJECT_SOURCE_DIR}/include"
        "${PROJECT_SOURCE_DIR}/src"
)

# 库文件存放位置
link_directories(
        "${PROJECT_SOURCE_DIR}/bin"             # 海康的动态库
)

# 需要连接的静态库文件
link_libraries(
        "dl"            # linux 动态链接库的操作dlfcn.h的库文件
        "uv"
        "mosquitto"
        "hcnetsdk"
        "iec61850"
        "pthread"
)

set(SOURCE_FILES
        src/ini.c
        src/main.c
        src/ry_mqtt.c
        src/ry_nvr_mgr.c
        src/ry_iec61850.c
        src/parson/parson.c
        )

# 测试程序
add_executable(test_dny "src/test_dynamic.c")

# 主程序
add_executable(RY_Service ${SOURCE_FILES})

# 海康的接口
ADD_LIBRARY(nvr2001 SHARED src/nvr_adps/hk_nvr.cpp)


