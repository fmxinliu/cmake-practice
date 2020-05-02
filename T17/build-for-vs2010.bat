@rem 构建编译目录
@ rmdir build-for-vs2010 /Q /S
@ mkdir build-for-vs2010
@ cd build-for-vs2010/

@rem 根据CMakeList.txt文件，生成平台相关的Makefile或工程文件
@ cmake .. -G "Visual Studio 10 2010"
@ if not %errorlevel%==0 @ goto :end

@rem 打包
@ cd ../build-for-vs2010
@ cpack

:end
@ pause
