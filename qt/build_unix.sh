#!/bin/bash

# 进入当前脚本所在的目录
cd "$(dirname "$(readlink -f "${BASH_SOURCE[0]}")")" || exit

# 设置Qt环境
PATH=~/Qt5.9.9/5.9.9/gcc_64/bin:$PATH

# 构建编译目录
[ -d "build_unix" ] && rm -rf build_unix
mkdir build_unix && cd build_unix

# 设置Unix build类型
BUILD_TYPE=Release

# 根据 CMakeLists.txt，生成 unix makefile 文件
cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=$BUILD_TYPE || exit

# 编译
make || exit

# 测试
export CTEST_OUTPUT_ON_FAILURE=1
make test && src/cmake_qt
