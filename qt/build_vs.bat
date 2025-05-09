@ setlocal & cd /d %~dp0

@rem 构建编译目录
@ if exist build_vs @ rmdir build_vs /Q /S
@ mkdir build_vs
@ cd build_vs

@rem 加载Build配置
@ call ..\..\BuildConfig.bat
@ if %errorlevel% neq 0 @ goto :end
 
@rem 设置Qt环境
@ set PATH=%qt_vs_bin_dir%;%PATH%
@ if %errorlevel% neq 0 @ goto :end

@rem 生成VS工程
@ "%cmake_exe%" .. -G %vs_generator_x64% 
@ if %errorlevel% neq 0 @ goto :end

@REM 设置VS工程build类型
@ set BUILD_TYPE=Release

@rem 编译
@ "%vs_build_exe%" cmake_qt.sln /Rebuild %BUILD_TYPE%
@ if %errorlevel% neq 0 @ goto :end

@rem 运行单元测试
@ set CTEST_OUTPUT_ON_FAILURE=1
@ "%ctest_exe%" -C %BUILD_TYPE%
@ if %errorlevel% neq 0 @ goto :end

@rem 运行主程序
@ src\%BUILD_TYPE%\cmake_qt.exe

:end
@ pause & endlocal
