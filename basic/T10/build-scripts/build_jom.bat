@ setlocal & cd /d %~dp0
@ chcp 65001 >nul

@rem 构建编译目录
@ if exist build_jom @ rmdir build_jom /Q /S
@ mkdir build_jom
@ cd build_jom

@rem 加载Build配置
@ call ..\..\..\BuildConfig.bat
@ if %errorlevel% neq 0 @ goto :end

@rem 设置编译器环境变量
@ call "%vs_tools_bat%"
@ if %errorlevel% neq 0 @ goto :end

@rem 根据 CMakeLists.txt，生成 jom makefile 文件
@ "%cmake_exe%" ..\.. -G "NMake Makefiles JOM" -DCMAKE_MAKE_PROGRAM=%jom_exe%
@ if %errorlevel% neq 0 @ goto :end

@rem 4核编译
@ %jom_exe% -j 4
@ if %errorlevel% neq 0 @ goto :end

@rem 运行
@ demo.exe

:end
@ pause & endlocal
