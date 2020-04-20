@rem lib exports style
@ cd ../src
@ call CMakeLists-generate.bat "extern \"C\"" __cdecl nopause

@rem lib test
@ cd ../
@ call build.bat nopause

@ if not "%1"=="nopause" @ pause
