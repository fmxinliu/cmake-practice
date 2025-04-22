# 指定cmake版本
cmake_minimum_required(VERSION 3.5)

# 指定工程名
project(cmake_qt LANGUAGES CXX)

# 设置 cmake 模块路径
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# 包含qt.cmake
include(qt)

# 添加子目录，进一步Make
add_subdirectory(src)
add_subdirectory(tests)

# 设置一些变量，可以全局使用

# 安装
