# 指定cmake版本
cmake_minimum_required(VERSION 3.5)

# 指定工程名
project(cmake_qt LANGUAGES CXX)

# 包含Qt配置
include(${PROJECT_SOURCE_DIR}/cmake/QtConfig.cmake)

# 添加子目录，进一步Make
add_subdirectory(src)
add_subdirectory(tests)

# 设置一些变量，可以全局使用

# 安装
