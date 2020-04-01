# CMake 最低版本号要求
cmake_minimum_required(VERSION 2.8)

# 项目名称
project(demo)

# 添加头文件目录
include_directories(${PROJECT_SOURCE_DIR}/math/include ${PROJECT_SOURCE_DIR}/util/include)

# 添加 util 子目录（必须包含CMakeLists.txt）
add_subdirectory(util)

# 查找当前目录下的所有源文件，保存到变量 DIR_SRCS
aux_source_directory(. DIR_SRCS)

# 指定生成目标
add_executable(${PROJECT_NAME} ${DIR_SRCS})

# 添加链接库
target_link_libraries(${PROJECT_NAME} UtilLib)   # 静态库
target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/math/lib/MathFunctions.lib) # 动态库