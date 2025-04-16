#!/bin/bash

# 进入当前脚本所在的目录
cd "$(dirname "$(readlink -f "${BASH_SOURCE[0]}")")" || exit

# 清理编译结果
[ -d "bin" ] && rm -rf bin
[ -d "lib" ] && rm -rf lib
ls *.zip >/dev/null 2>&1 && rm -f *.zip

# 构建编译目录
[ -d "build_unix" ] && rm -rf build_unix
mkdir build_unix && cd build_unix

# 根据 CMakeLists.txt，生成 unix makefile 文件
cmake .. -G "Unix Makefiles" || exit

# 编译
make || exit

# 运行
cd ../bin && ./hello

# 打包
cd ../build_unix && make package
