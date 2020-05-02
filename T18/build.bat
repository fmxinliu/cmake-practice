@rem 清除生成文件
@ rmdir bin /Q /S
@ rmdir lib /Q /S
@ del *.zip /Q /F

@rem 构建编译目录
@ rmdir build-for-unix-make /Q /S
@ mkdir build-for-unix-make
@ cd build-for-unix-make/

@rem 根据 CMakeLists.txt，生成 unix makefile 文件
@ cmake .. -G "Unix Makefiles" -DCMAKE_MAKE_PROGRAM=%MINGW_TOOLS%make.exe
@ if not %errorlevel%==0 @ goto :end

@rem 编译
@ %MINGW_TOOLS%make.exe
@ if not %errorlevel%==0 @ goto :end

@rem 测试
@ cd ../bin
@ copy ..\lib\liblibhello.dll .\ /Y > nul
@ hello.exe

@rem 打包
@ cd ../build-for-unix-make
@ make package

:end
@ pause
