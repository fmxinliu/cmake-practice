# CMake 最低版本号要求
cmake_minimum_required(VERSION 2.8)

# 项目名称
project(demo)

# 指定生成目标
add_executable(demo main.cpp MathFunctions.cpp)

# 如果当前目录中有很多源文件
#aux_source_directory(. DIR_SRCS)  #查找当前目录下的所有源文件，保存到变量 DIR_SRCS
#add_executable(demo ${DIR_SRCS})  #指示变量 DIR_SRCS 的源文件需要生成一个名为 demo 的可执行文件