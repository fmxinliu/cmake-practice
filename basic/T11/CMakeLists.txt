# CMake 最低版本号要求
cmake_minimum_required(VERSION 2.8)

# 项目名称
project(demo_install)

# 添加 math 子目录（必须包含CMakeLists.txt）
add_subdirectory(math)

# 查找当前目录下的所有源文件，保存到变量 DIR_SRCS
aux_source_directory(. DIR_SRCS)

# 指定生成目标
add_executable(demo ${DIR_SRCS})

# 添加链接库
target_link_libraries(demo MathFunctions)

# 指定 demo 的安装路径
install(TARGETS demo DESTINATION bin)

# 指定安装根目录
set(CMAKE_INSTALL_PREFIX "${PROJECT_BINARY_DIR}/install/")