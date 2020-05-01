@rem 构建编译目录
@ rmdir build /Q /S
@ mkdir build
@ cd build/

@rem 根据CMakeList.txt文件，生成平台相关的Makefile或工程文件
@ cmake .. -G "Visual Studio 10 2010"
@ if %errorlevel% neq 0 @ goto :end

@rem 编译
@ "C:\Program Files (x86)\Microsoft Visual Studio 10.0\Common7\IDE\devenv.exe" demo.sln /Rebuild "Release"

@rem 运行
@ cd Release/
@ copy ..\..\lib\libhello.dll .\ /Y > nul
@ hello.exe

:end
@ pause
