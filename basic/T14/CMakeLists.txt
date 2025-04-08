# CMake 最低版本号要求
cmake_minimum_required(VERSION 2.8)

# 项目名称
project(demo)

# (1)指定主/次版本号
set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)

# (2)加入一个配置头文件 config.h，从 config.h.in 生成，使得可以通过预定义一些参数和变量来控制代码的生成
configure_file(
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_SOURCE_DIR}/config.h"
)

# 查找当前目录下的所有源文件，保存到变量 DIR_SRCS
aux_source_directory(. DIR_SRCS)

# 指定生成目标
add_executable(${PROJECT_NAME} ${DIR_SRCS})