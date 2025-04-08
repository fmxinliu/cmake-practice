# CMake 最低版本号要求
cmake_minimum_required(VERSION 2.8)

# 项目名称
project(demo)

# 添加头文件目录
include_directories(${PROJECT_SOURCE_DIR}/math/include)

# 添加链接库目录(必须要放到add_executable前面，否则不生效；建议不要使用link_directories，直接放在target_link_libraries中)
#link_directories(${PROJECT_SOURCE_DIR}/math/lib)

# 查找当前目录下的所有源文件，保存到变量 DIR_SRCS
aux_source_directory(. DIR_SRCS)

# 指定生成目标
add_executable(demo ${DIR_SRCS})

# 添加链接库
#target_link_libraries(demo MathFunctions.lib)
target_link_libraries(demo ${PROJECT_SOURCE_DIR}/math/lib/MathFunctions.lib)