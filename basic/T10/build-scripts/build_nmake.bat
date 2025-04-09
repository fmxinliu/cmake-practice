@ setlocal & cd /d %~dp0

@rem 构建编译目录
@ if exist build_nmake @ rmdir build_nmake /Q /S
@ mkdir build_nmake
@ cd build_nmake

@rem 加载Build配置
@ call ..\..\..\BuildConfig.bat
@ if %errorlevel% neq 0 @ goto :end

@rem 设置编译器环境变量
@ call "%vs_tools_bat%"
@ if %errorlevel% neq 0 @ goto :end

@rem 根据 CMakeLists.txt，生成 nmake makefile 文件（平台相关）
@ "%cmake_exe%" ..\.. -G "NMake Makefiles"
@ if %errorlevel% neq 0 @ goto :end

@rem 编译
@ nmake
@ if %errorlevel% neq 0 @ goto :end

@rem 运行
@ demo.exe

:end
@ pause & endlocal
