@rem 构建编译目录
@ rmdir build-for-jom /Q /S
@ mkdir build-for-jom
@ cd build-for-jom/

@rem 设置编译器环境变量
@ call "%VS100COMNTOOLS%vsvars32.bat"

@rem 根据 CMakeLists.txt，生成 jom makefile 文件
@ cmake ../.. -G "NMake Makefiles JOM" -DCMAKE_MAKE_PROGRAM=%QT53TOOLS%jom.exe

@rem 4核编译
@ %QT53TOOLS%jom -j 4

@rem 运行
@ demo.exe

@ pause
