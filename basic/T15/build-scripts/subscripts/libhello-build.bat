@ setlocal

@rem 清除生成的头文件
@ cd ../
@ if exist include\libhello.h @ del include\libhello.h /f /q

@rem 构建编译目录
@ if exist build @ rmdir build /q /s
@ mkdir build
@ cd build/

@rem 加载Build配置
@ call ..\..\..\BuildConfig.bat
@ if %errorlevel% neq 0 @ goto :end

@rem 根据CMakeList.txt文件，生成平台相关的Makefile或工程文件
@ "%cmake_exe%" .. -G %vs_generator_x86%
@ if %errorlevel% neq 0 @ goto :end

@rem 编译
@ "%vs_build_exe%" demo.sln /Rebuild "Release"
@ if %errorlevel% neq 0 @ goto :end

@rem 运行
@ cd bin/Release/
@ hello.exe

:end
@ if not "%1"=="nopause" @ pause
