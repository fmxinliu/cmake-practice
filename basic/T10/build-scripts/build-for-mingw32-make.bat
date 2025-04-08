@rem 构建编译目录
@ rmdir build-for-mingw32-make /Q /S
@ mkdir build-for-mingw32-make
@ cd build-for-mingw32-make/

@rem 根据 CMakeLists.txt，生成 mingw makefile 文件
@ cmake ../.. -G "MinGW Makefiles" -DCMAKE_MAKE_PROGRAM=%MINGW_TOOLS%mingw32-make.exe

@rem 4核编译
@ %MINGW_TOOLS%mingw32-make.exe -j 4

@rem 运行
@ demo.exe

@ pause
