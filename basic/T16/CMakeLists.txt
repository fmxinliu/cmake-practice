# CMake 最低版本号要求
cmake_minimum_required(VERSION 2.8)

# 项目名称
project(demo)

# 指定Find_<name>.cmake模块所在的目录（必须放在调用前）
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# 指定可执行文件生成目录
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

# 添加 src 子目录（必须包含CMakeLists.txt）
add_subdirectory(src)

