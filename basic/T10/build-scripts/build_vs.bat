@ setlocal & cd /d %~dp0

@rem 构建编译目录
@ if exist build_vs @ rmdir build_vs /Q /S
@ mkdir build_vs
@ cd build_vs

@rem 加载Build配置
@ call ..\..\..\BuildConfig.bat
@ if %errorlevel% neq 0 @ goto :end

@rem 生成VS工程
@ "%cmake_exe%" ..\.. -G %vs_generators%
@ if %errorlevel% neq 0 @ goto :end

@rem 编译
@ "%vs_build_exe%" hello.sln /Rebuild "Release"
@ if %errorlevel% neq 0 @ goto :end

@rem 运行
@ cd Release
@ demo.exe

:end
@ pause & endlocal
