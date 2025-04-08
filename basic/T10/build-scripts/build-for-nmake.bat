@rem 构建编译目录
@ rmdir build-for-nmake /Q /S
@ mkdir build-for-nmake
@ cd build-for-nmake/

@rem 设置编译器环境变量
@ call "%VS100COMNTOOLS%vsvars32.bat"

@rem 根据 CMakeLists.txt，生成 nmake makefile 文件（平台相关）
@ cmake ../.. -G "NMake Makefiles"

@rem 编译
@ nmake

@rem 运行
@ demo.exe

@ pause
