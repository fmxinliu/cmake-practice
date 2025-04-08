@rem 构建编译目录
@ if exist config.h @del config.h /Q /F 
@ rmdir build /Q /S
@ mkdir build
@ cd build/

@rem 根据CMakeList.txt文件，生成平台相关的Makefile或工程文件
@ cmake .. -G "Visual Studio 10 2010"

@rem 编译
@ "C:\Program Files (x86)\Microsoft Visual Studio 10.0\Common7\IDE\devenv.exe" demo.sln /Rebuild "Release"

@rem 运行
@ cd Release/
@ demo.exe 5 4

@ pause
