@rem 构建编译目录
@ rmdir build-for-vs2010 /Q /S
@ mkdir build-for-vs2010
@ cd build-for-vs2010/

@rem 根据 CMakeLists.txt，生成 vs2010 工程文件（平台相关）
@ cmake ..\.. -G "Visual Studio 10 2010"

@rem 编译
@ "C:\Program Files (x86)\Microsoft Visual Studio 10.0\Common7\IDE\devenv.exe" hello.sln /Rebuild "Release"

@rem 运行
@ cd Release/
@ demo.exe

@ pause
