@ setlocal & cd /d %~dp0

@rem 清除生成文件
@ if exist bin @ rmdir bin /Q /S
@ if exist lib @ rmdir lib /Q /S
@ if exist *.zip @ del *.zip /Q /F

@rem 构建编译目录
@ if exist build_vs @ rmdir build_vs /Q /S
@ mkdir build_vs
@ cd build_vs

@rem 加载Build配置
@ call ..\..\BuildConfig.bat
@ if %errorlevel% neq 0 @ goto :end

@rem 生成VS工程
@ "%cmake_exe%" .. -G %vs_generators%
@ if %errorlevel% neq 0 @ goto :end

@rem 编译
@ "%vs_build_exe%" hello.sln /Rebuild "Release"
@ if %errorlevel% neq 0 @ goto :end

@rem 部署
@ xcopy Release\libhello.lib ..\lib\ /V /C /I /R /K /Y >nul
@ xcopy Release\libhello.dll ..\lib\ /V /C /I /R /K /Y >nul
@ xcopy Release\libhello.dll ..\bin\ /V /C /I /R /K /Y >nul
@ xcopy Release\hello.exe    ..\bin\ /V /C /I /R /K /Y >nul

@rem 测试
@ cd ..\bin
@ hello.exe

@rem 打包
@ cd ..\build_vs
@ %cpack_exe%

:end
@ pause & endlocal
