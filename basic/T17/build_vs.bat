@ setlocal & cd /d %~dp0

@rem 构建编译目录
@ if exist build_vs @ rmdir build_vs /Q /S
@ mkdir build_vs
@ cd build_vs

@rem 加载Build配置
@ call ..\..\..\BuildConfig.bat
@ if %errorlevel% neq 0 @ goto :end

@rem 生成VS工程
@ "%cmake_exe%" .. -G %vs_generator_x86%
@ if %errorlevel% neq 0 @ goto :end

@rem 打包
@ cd ..\build_vs
@ %cpack_exe%

:end
@ pause & endlocal
