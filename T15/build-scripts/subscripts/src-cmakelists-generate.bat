@ setlocal enabledelayedexpansion

@rem 参数解析
@ if not x_%1==x_nopause @ set DLL_CALL_CONVENTIONS_VALUE=%1
@ if not x_%2==x_nopause @ set DLL_STYLE_VALUE=%2
@ if not x_%3==x_nopause @ set DLL_EXPORTS_VALUE=%3
@ if not x_%4==x_nopause @ set DLL_EXPORTS_DEF_FILE_VALUE=%4

@rem 参数检查
@ if x%DLL_CALL_CONVENTIONS_VALUE%==x @ set DLL_CALL_CONVENTIONS_VALUE=""
@ if x%DLL_STYLE_VALUE%==x            @ set DLL_STYLE_VALUE=""
@ if x%DLL_EXPORTS_VALUE%==x          @ set DLL_EXPORTS_VALUE=DLL_EXPORTS
@ if x%DLL_EXPORTS_DEF_FILE_VALUE%==x @ set DLL_EXPORTS_DEF_FILE_VALUE=""

@rem 文件路径
@ set file_path=..\src\CMakeLists.txt
@ set tmpl_path=..\src\CMakeLists.tmpl

@rem 动态库导出参数
@ set DLL_CALL_CONVENTIONS=DLL_CALL_CONVENTIONS_DEFINE
@ set DLL_STYLE=DLL_STYLE_DEFINE
@ set DLL_EXPORTS=DLL_EXPORTS_DEFINE
@ set DLL_EXPORTS_DEF_FILE=DLL_EXPORTS_DEF_FILE_DEFINE

@rem 生成 CMakeLists.txt
@ if exist %file_path% @ del %file_path% /f /q
@ for /f "tokens=*" %%i in (%tmpl_path%) do @(
    @ set s=%%i
    @ set s=!s:%DLL_CALL_CONVENTIONS%=%DLL_CALL_CONVENTIONS_VALUE%!
    @ set s=!s:%DLL_STYLE%=%DLL_STYLE_VALUE%!
    @ set s=!s:%DLL_EXPORTS%=%DLL_EXPORTS_VALUE%!
    @ set s=!s:%DLL_EXPORTS_DEF_FILE%=%DLL_EXPORTS_DEF_FILE_VALUE%!
    @ echo !s! >> %file_path%
)

@rem ---
@ for %%a in (%*) do @ if "%%a"=="nopause" @ exit /b 0
@ pause
