@rem 清除生成文件
@ rmdir bin /Q /S
@ rmdir lib /Q /S
@ del *.zip /Q /F

@rem 构建编译目录
@ rmdir build-for-vs2010 /Q /S
@ mkdir build-for-vs2010
@ cd build-for-vs2010/

@rem 根据CMakeList.txt文件，生成VC工程文件
@ cmake .. -G "Visual Studio 10 2010"
@ if not %errorlevel%==0 @ goto :end

@rem 编译
@ "C:\Program Files (x86)\Microsoft Visual Studio 10.0\Common7\IDE\devenv.exe" hello.sln /Rebuild "Release"
@ if not %errorlevel%==0 @ goto :end

@rem 部署
@ xcopy Release\libhello.lib ..\lib\ /V /C /I /R /K /Y >nul
@ xcopy Release\libhello.dll ..\lib\ /V /C /I /R /K /Y >nul
@ xcopy Release\libhello.dll ..\bin\ /V /C /I /R /K /Y >nul
@ xcopy Release\hello.exe    ..\bin\ /V /C /I /R /K /Y >nul

@rem 测试
@ cd ../bin
@ hello.exe

@rem 打包
@ cd ../build-for-vs2010
@ cpack

:end
@ pause
