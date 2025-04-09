#!/bin/bash

# 构建编译目录
[ -d "build_unix" ] && rm -rf build_unix
mkdir build_unix && cd build_unix

# 根据 CMakeLists.txt，生成 unix makefile 文件
cmake ../.. -G "Unix Makefiles" || exit

# 编译
make || exit

# 运行
./demo
