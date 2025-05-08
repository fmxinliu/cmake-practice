@ setlocal & cd /d %~dp0

@rem 构建编译目录
@ if exist build_mingw @ rmdir build_mingw /Q /S
@ mkdir build_mingw
@ cd build_mingw

@rem 加载Build配置
@ call ..\..\BuildConfig.bat
@ if %errorlevel% neq 0 @ goto :end
 
@rem 设置Qt环境
@ set PATH=%qt_mingw_bin_dir%;%qt_mingw_tools_dir%;%PATH%
@ if %errorlevel% neq 0 @ goto :end

@rem 根据 CMakeLists.txt，生成 mingw makefile 文件
@ "%cmake_exe%" .. -G "MinGW Makefiles"
@ if %errorlevel% neq 0 @ goto :end

@rem 编译
@ "%qt_mingw_make_exe%"
@ if %errorlevel% neq 0 @ goto :end

@rem 运行单元测试
@ "%qt_mingw_make_exe%" test
@ if %errorlevel% neq 0 @ goto :end

@rem 运行主程序
@ src\cmake_qt.exe

:end
@ pause & endlocal
