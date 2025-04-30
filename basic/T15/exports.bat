@ setlocal enabledelayedexpansion
@ setlocal & cd /d %~dp0

@rem 加载Build配置
@ call ..\..\BuildConfig.bat
@ if !errorlevel! neq 0 @ goto :end

@rem 编译导出
@ if exist exports @ rmdir exports /q /s
@ set root_path=!cd!\
@ set build_path=!root_path!build-scripts\
@ set lib_path=!root_path!build\bin\Release\
@ set export_path=!root_path!exports\

@ call :export !build_path!
@ call :export !build_path!\defscripts\ def-

:end
@ endlocal
@ setlocal disabledelayedexpansion
@ if not "%1"=="nopause" @ pause
@ goto :eof

:export
@ set bat_path=%1
@ set prefix=%2
@ for %%f in (!bat_path!*.bat) do @(
    set full_name=%%f
    set bat_name=!full_name:%bat_path%=!
    set dir_name=!prefix!!bat_name:~0,-4!
    set file_name=!dir_name!.txt
    
    rem 测试动态库
    cd !bat_path!
    call !bat_name! nopause

    rem 拷贝动态库
    xcopy !lib_path!libhello.* !export_path!!dir_name!\
    
    rem 查看动态库
    "%dumpbin_exe%" /exports !export_path!!dir_name!\libhello.dll > !export_path!!file_name!
)
