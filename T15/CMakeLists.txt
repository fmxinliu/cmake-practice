# CMake 最低版本号要求
cmake_minimum_required(VERSION 2.8)

# 项目名称
project(demo)

# 添加头文件目录
include_directories(${PROJECT_SOURCE_DIR}/include)

# 添加 src 子目录（必须包含CMakeLists.txt）
add_subdirectory(src)

# 查找当前目录下的所有源文件，保存到变量 DIR_SRCS
aux_source_directory(. DIR_SRCS)

# 指定生成目标
add_executable(hello ${DIR_SRCS})

# 添加链接库
target_link_libraries(hello libhello)

# 指定可执行文件生成目录
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/bin)