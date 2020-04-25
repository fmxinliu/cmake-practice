@rem lib exports style
@ call subscripts/src-cmakelists-generate.bat %1 %2 %3 %4 nopause

@rem build
@ call subscripts/libhello-build.bat nopause

@rem ---
@ for %%a in (%*) do @ if "%%a"=="nopause" @ exit /b 0
@ pause
