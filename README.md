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

##### 任务5 ：生成多文件多目录工程（动态链接库），并更改可执行文件和库文件生成目录

```
T5/
| -- build.bat
| -- CMakeLists.txt
| -- main.cpp
| -- math
     | -- CMakeLists.txt
     | -- MathFunctions.cpp
     | -- MathFunctions.h
| -- build/
     | -- bin/
          | -- Release/
               | -- demo.exe
               | -- MathFunctions.dll
               | -- MathFunctions.lib             
```

##### 任务6 ：生成调用动态链接库的工程

```
T6/
| -- build.bat
| -- CMakeLists.txt
| -- main.cpp
| -- math
     | -- include
          | -- MathFunctions.h
     | -- lib
          | -- MathFunctions.dll
          | -- MathFunctions.lib
```

##### 任务7 ：生成调用动态链接库+静态链接库的工程

```
T7/
| -- build.bat
| -- CMakeLists.txt
| -- main.cpp
| -- math
     | -- include
          | -- MathFunctions.h
     | -- lib
          | -- MathFunctions.dll
          | -- MathFunctions.lib
| -- util
     | -- include
          | -- bye.h
          | -- hello.h
     | -- src
          | -- bye.cpp
          | -- CMakeLists.txt
          | -- hello.cpp
     | -- CMakeLists.txt
```
