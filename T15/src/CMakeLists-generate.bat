@ setlocal enabledelayedexpansion

@rem 文件路径
@ set file_path=CMakeLists.txt
@ set tmpl_path=CMakeLists.tmpl

@rem 动态库导出参数
@ set DLL_CALL_CONVENTIONS=DLL_CALL_CONVENTIONS_DEFINE
@ set DLL_STYLE=DLL_STYLE_DEFINE
@ set DLL_EXPORTS=DLL_EXPORTS_DEFINE
@ set DLL_EXPORTS_DEF_FILE=DLL_EXPORTS_DEF_FILE_DEFINE

@rem 生成 CMakeLists.txt
@ if exist %file_path% @ del %file_path% /f /q
@ for /f "tokens=*" %%i in (%tmpl_path%) do @(
    @ set s=%%i
    @ set s=!s:%DLL_STYLE%=%1!
    @ set s=!s:%DLL_CALL_CONVENTIONS%=%2!
    @if %3==nopause @(
      @set s=!s:%DLL_EXPORTS%=DLL_EXPORTS!
    ) else (
      @set s=!s:%DLL_EXPORTS%=%3!
    )
    @set s=!s:%DLL_EXPORTS_DEF_FILE%=%4!
    @ echo !s! >> %file_path%
)

@rem ---
@ for %%a in (%*) do @ if "%%a"=="nopause" @ exit /b 0
@ pause
