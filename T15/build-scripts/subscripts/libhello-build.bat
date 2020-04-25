@ setlocal

@rem 清除生成的头文件
@ cd ../
@ if exist include\libhello.h @ del include\libhello.h /f /q 

@rem 构建编译目录
@ rmdir build /q /s
@ mkdir build
@ cd build/

@rem 根据CMakeList.txt文件，生成平台相关的Makefile或工程文件
@ cmake .. -G "Visual Studio 10 2010"

@rem 编译
@ "C:\Program Files (x86)\Microsoft Visual Studio 10.0\Common7\IDE\devenv.exe" demo.sln /Rebuild "Release"

@rem 运行
@ cd bin/Release/
@ hello.exe

@ if not "%1"=="nopause" @ pause
