@ setlocal & cd /d %~dp0

@rem 构建编译目录
@ if exist config.h @ del config.h /Q /F
@ if exist build @ rmdir build /Q /S
@ mkdir build
@ cd build

@rem 加载Build配置
@ call ..\..\..\BuildConfig.bat
@ if %errorlevel% neq 0 @ goto :end

@rem 生成VS工程
@ echo After Configure and Generate project, close the cmake-gui window to continue...
@ cmake-gui ..
@rem "%cmake_exe%" .. -G %vs_generator_x86%

@rem 编译
@ "%vs_build_exe%" demo.sln /Rebuild "Release"
@ if %errorlevel% neq 0 @ goto :end

@rem 运行
@ cd Release
@ demo.exe 5 4

:end
@ pause & endlocal
