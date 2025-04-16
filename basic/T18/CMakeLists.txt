# CMake 最低版本号要求
cmake_minimum_required(VERSION 3.0)

# 项目名称
project(hello)

# 选择生成共享/静态库
option(BUILD_SHARED_LIBS "Build shared libraries" ON)
if(BUILD_SHARED_LIBS)
    add_definitions(-D LIBRARY_SHARED)
endif()

# 添加头文件目录
include_directories(${PROJECT_SOURCE_DIR}/include)

# 添加 src 子目录（必须包含CMakeLists.txt）
add_subdirectory(src)

# 设置rpath（必须在 add_executable 前指定）
if(BUILD_SHARED_LIBS)
    set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
    set(CMAKE_INSTALL_RPATH "\${ORIGIN}/../lib")
endif()

# 指定生成目标
add_executable(hello main.cpp)

# 添加链接库
target_link_libraries(hello libhello)

# 指定可执行文件生成目录
if(MSVC)
    set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})
else(MSVC)
    set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
endif(MSVC)

# 指定打包结构
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/vInstallCpack.cmake)
