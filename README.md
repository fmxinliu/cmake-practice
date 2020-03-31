##### 任务1 ：生成单个源文件工程

```
T1/
| -- build.bat
| -- CMakeLists.txt
| -- main.cpp
```

##### 任务2 ：生成单目录多源文件工程

```
T2/
| -- build.bat
| -- CMakeLists.txt
| -- main.cpp
| -- MathFunctions.cpp
| -- MathFunctions.h
```

##### 任务3 ：生成多文件多目录工程（静态链接库）

```
T3/
| -- build.bat
| -- CMakeLists.txt
| -- main.cpp
| -- math
     | -- CMakeLists.txt
     | -- MathFunctions.cpp
     | -- MathFunctions.h
```

##### 任务4 ：生成多文件多目录工程（动态链接库）

```
T4/
| -- build.bat
| -- CMakeLists.txt
| -- main.cpp
| -- math
     | -- CMakeLists.txt
     | -- MathFunctions.cpp
     | -- MathFunctions.h
| -- build/
     | -- math/
          | -- Release/
               | -- MathFunctions.dll
               | -- MathFunctions.lib
     | -- Release/
          | -- demo.exe
```
