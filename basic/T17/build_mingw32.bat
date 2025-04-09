@ setlocal & cd /d %~dp0

@rem 构建编译目录
@ if exist build_unix @ rmdir build_unix /Q /S
@ mkdir build_unix
@ cd build_unix

@rem 加载Build配置
@ call ..\..\BuildConfig.bat
@ if %errorlevel% neq 0 @ goto :end

@rem 根据 CMakeLists.txt，生成 mingw makefile 文件
@ "%cmake_exe%" .. -G "MinGW Makefiles" -DCMAKE_MAKE_PROGRAM=%make_exe%
@ if %errorlevel% neq 0 @ goto :end

@rem 打包
@ %make_exe% package

:end
@ pause & endlocal
