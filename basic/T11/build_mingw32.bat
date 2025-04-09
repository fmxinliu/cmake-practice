@ setlocal & cd /d %~dp0

@rem 构建编译目录
@ if exist build @ rmdir build /Q /S
@ mkdir build
@ cd build

@rem 加载Build配置
@ call ..\..\BuildConfig.bat
@ if %errorlevel% neq 0 @ goto :end

@rem 根据 CMakeLists.txt，生成 mingw makefile 文件
@ "%cmake_exe%" .. -G "MinGW Makefiles" -DCMAKE_MAKE_PROGRAM=%make_exe%
@ if %errorlevel% neq 0 @ goto :end

@rem 编译
@ %make_exe%
@ if %errorlevel% neq 0 @ goto :end

@rem 运行
@ demo.exe

@rem 安装
@ %make_exe% install
@ if %errorlevel% neq 0 @ goto :end

@rem 进入安装目录，运行
@ cd install\bin
@ demo.exe 5 4

:end
@ pause & endlocal
