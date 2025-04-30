@ setlocal & cd /d %~dp0

@rem 构建编译目录
@ if exist build_mingw @ rmdir build_mingw /Q /S
@ mkdir build_mingw
@ cd build_mingw

@rem 加载Build配置
@ call ..\..\..\BuildConfig.bat
@ if %errorlevel% neq 0 @ goto :end

@rem 设置MinGW环境
@ set PATH=%mingw_bin_dir%;%PATH%
@ if %errorlevel% neq 0 @ goto :end

@rem 根据 CMakeLists.txt，生成 mingw makefile 文件
@ "%cmake_exe%" .. -G "MinGW Makefiles"
@ if %errorlevel% neq 0 @ goto :end

@rem 打包
@ "%mingw_make_exe%" package

:end
@ pause & endlocal
