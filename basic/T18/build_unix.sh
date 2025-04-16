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

# 测试
## 1.将 bin 和 lib 移动到 test 目录下
cd .. && [ -d "test" ] && rm -rf test
mkdir test
mv bin test
mv lib test

## 2.执行程序
if ./test/bin/hello; then
    readelf -d test/bin/hello | grep RUNPATH
else
    ldd test/bin/hello
    exit 1
fi

## 3.恢复 bin 和 lib 目录
mv test/bin .
mv test/lib .

# 打包
cd build_unix && make package