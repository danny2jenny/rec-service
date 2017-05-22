cmake_minimum_required(VERSION 3.6)
project(RY_Service)

SET(CMAKE_GENERATOR “MSYS Makefiles”)
#set(CMAKE_C_STANDARD 99)
#SET(CMAKE_C_FLAGS_DEBUG "-D_DEBUG")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

# 设置RPATH
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-rpath,'$ORIGIN'")
SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-rpath,'$ORIGIN'")

# 设置编译后文件的输出位置
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 工程中头文件存放位置
include_directories(
        # 包含该工程的头文件
        "${PROJECT_SOURCE_DIR}/include"
        "${PROJECT_SOURCE_DIR}/src"
)

# 静态库文件存放位置
link_directories(
        "${PROJECT_SOURCE_DIR}/bin"
)

# 需要连接的静态库文件
link_libraries(
        "dl"            # linux 动态链接库的操作dlfcn.h的库文件
        "uv"
        "mosquitto"
        "hcnetsdk"
)

set(SOURCE_FILES
        src/main.c
        src/ry_msg.c
        src/ry_video_adapter.c
        src/parson/parson.c
        )

# 主程序
add_executable(RY_Service ${SOURCE_FILES})

# 海康的接口
ADD_LIBRARY(nvr2001 SHARED src/hk_nvr/hk_nvr.cpp)
