@rem 构建编译目录
@ rmdir build-for-unix-make /Q /S
@ mkdir build-for-unix-make
@ cd build-for-unix-make/

@rem 根据 CMakeLists.txt，生成 unix makefile 文件
@ cmake .. -G "Unix Makefiles" -DCMAKE_MAKE_PROGRAM=%MINGW_TOOLS%make.exe
@ if not %errorlevel%==0 @ goto :end

@rem 打包
@ make package

:end
@ pause
