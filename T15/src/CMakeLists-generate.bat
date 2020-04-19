@setlocal enabledelayedexpansion

@rem 文件路径
@set file_path=CMakeLists.txt
@set tmpl_path=CMakeLists.tmpl
@set temp_path=CMakeLists.temp

@rem 动态库生成参数
@set DLL_STYLE=DLL_STYLE_VALUE
@set CALL_CONVENTIONS=CALL_CONVENTIONS_VALUE

@rem 临时文件
@if exist %temp_path% @del %temp_path% /f /q

@for /f "tokens=*" %%i in (%tmpl_path%) do @(
    @set s=%%i
    @set s=!s:%DLL_STYLE%=%1!
    @set s=!s:%CALL_CONVENTIONS%=%2!
    @echo !s!>>%temp_path%
)

@move %temp_path% %file_path%

@for %%a in (%*) do @if "%%a"=="nopause" @exit /b 0
@pause