#### [**CMake 入门实战**](http://hahack.com/codes/cmake) | [**CMake高级用法**](https://haoqchen.site/2019/02/26/cmake-advance-usage/)

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

##### 任务8 ：生成调用动态链接库+静态链接库的工程（多文件多目录）

```
T8/
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
          | -- bye
               | -- bye.h
          | -- hello
               | -- hello.h
     | -- src
          | -- bye
               | -- bye.cpp
               | -- CMakeLists.txt
          | -- hello
               | -- CMakeLists.txt
               | -- hello.cpp
          | -- CMakeLists.txt
     | -- CMakeLists.txt
```

##### 任务9 ：自定义编译选项

```
T9/
| -- build.bat
| -- CMakeLists.txt
| -- config.h.in  cmake配置项文件
| -- main.cpp
| -- math
     | -- CMakeLists.txt
     | -- MathFunctions.cpp
     | -- MathFunctions.h
```

- `USE_MYMATH` 为 `ON`， config.h 的内容为：`#define USE_MYMATH`，运行结果为：

  ```
  Now we use our own Math library.
  5 ^ 4 is 625
  ```

- `USE_MYMATH` 为 `OFF`， config.h 的内容为：`/* #undef USE_MYMATH */`，运行结果为：

  ```
  Now we use the standard library.
  5 ^ 4 is 625
  ```

##### 任务10 ：多编译器构建

```
T10/
| -- CMakeLists.txt
| -- main.cpp
| -- build-scripts
     | -- build-for-jom.bat
     | -- build-for-mingw32-make.bat
     | -- build-for-nmake.bat
     | -- build-for-unix-make.bat
     | -- build-for-vs2010.bat
```

* 生成 `vs2010` 工程文件，安装 [vs2010](https://msdn.itellyou.cn/) 。
* 生成 `nmake` 构建规则的 `Makefile` 文件，安装 [vs2010](https://msdn.itellyou.cn/) 。
* 生成 `jom` 多核构建规则的 `Makefile` 文件，安装 [vs2010](https://msdn.itellyou.cn/)、[qt](http://download.qt.io/archive/qt/) 。
* 生成 `mingw` 多核构建规则的 `Makefile` 文件，安装 [mingw32-g++](https://mirrors.tuna.tsinghua.edu.cn/osdn/mingw/68260/mingw-get-setup.exe)、[mingw32-make](https://jaist.dl.sourceforge.net/project/mingw/MinGW/Extension/make/mingw32-make-3.80-3/mingw32-make-3.80.0-3.exe)。
* 生成 `unix` 多核构建规则的 `Makefile` 文件，复制`mingw\bin`目录下的`mingw32-make.exe`，改名为`make.exe`。参考[windows+CMake+mingw 搭建c/c++开发环境](https://www.cnblogs.com/herelsp/p/8679200.html)。

##### 任务11 ：定制安装规则

```
T11/
| -- CMakeLists.txt
| -- main.cpp
| -- build-for-unix-make/
     | -- install/
          | -- bin/
               | -- demo.exe
               | -- libMathFunctions.a
          | -- include/
               | -- MathFunctions.h   
```

* 指定 `MathFunctions` 库的安装路径。
* 指定 `MathFunctions.h` 的安装路径。
* 指定 `demo` 的安装路径。
* 指定安装根目录。

##### 任务12 ：添加测试

```
T12/
| -- CMakeLists.txt
| -- main.cpp
| -- build-for-unix-make/
```

##### 任务13 ：添加环境检查

```
T13/
| -- build.bat
| -- CMakeLists.txt
| -- config.h.in  cmake配置项文件
| -- main.cpp
| -- math
     | -- CMakeLists.txt
     | -- MathFunctions.cpp
     | -- MathFunctions.h
```

- 如果系统支持`pow`函数，config.h 的内容为：`#define HAVE_POW`，运行结果为：

  ```
  Now we use the standard library.
  5 ^ 4 is 625
  ```

- 如果系统不支持`pow`函数，config.h 的内容为：`/* #undef HAVE_POW */`，运行结果为：

  ```
  Now we use our own Math library.
  5 ^ 4 is 625
  ```

##### 任务14 ：添加版本号

```
T14/
| -- build.bat
| -- CMakeLists.txt
| -- config.h.in  cmake配置项文件
| -- main.cpp
```

* 在顶层 `CMakeLists` 定义版本号变量。
* 在 `config.h.in` 引用版本号变量，预定义宏。
* 在 `main.cpp` 引用预定义宏。

##### 任务15 ：windows 动态链接库导出方式对比

```
T15/
| -- build-scripts
     | -- defscripts
          | -- style-for-cdecl.bat
          | -- style-for-cdecl-c.bat
          | -- style-for-fastcall.bat
          | -- style-for-fastcall-c.bat
          | -- style-for-stdcall.bat
          | -- style-for-stdcall-c.bat
     | -- subscripts
          | -- libhello-build.bat
          | -- libhello-export-style.bat
          | -- src-cmakelists-generate.bat
     | -- style-for-cdecl.bat
     | -- style-for-cdecl-c.bat
     | -- style-for-fastcall.bat
     | -- style-for-fastcall-c.bat
     | -- style-for-stdcall.bat
     | -- style-for-stdcall-c.bat
| -- demo
     | -- C++/
     | -- CSharp/
     | -- dllstdcall
          | -- libhello.dll
     | -- .gitignore
     | -- Invoker.sln
| -- include
     | -- dllexport.h
     | -- libhello.h.in
| -- module
     | -- libhello.def
| -- src
     | -- CMakeLists.tmpl
     | -- libhello.cpp
| -- .gitignore
| -- CMakeLists.txt
| -- exports.bat
| -- export-style-diff.md
| -- export-style-diff.png
| -- export-style-diff.vsd
| -- main.cpp
```

* `build-scripts` → 动态库导出脚本。
* `demo` → 提供 C/C++ 通过 dll 调用导出函数的简单例子。
* `module` → def模块定义文件。
* `exports.bat` → 按多种方式导出动态库。
* `export-style-diff.md` → 不同方式导出的动态库对比。
* `export-style-diff.png/export-style-diff.vsd` → __cdecl 调用规约下，动态库导出树形图。

参考：*[windows下dll导出函数的两种方式的比较](https://www.cnblogs.com/talenth/p/9585208.html)*

##### 任务16 ：自定义模块

```
T16/
| -- cmake
     | -- FindHELLO.cmake
| -- lib
     | -- dllexport.h
     | -- libhello.dll
     | -- libhello.h
     | -- libhello.lib
| -- src
     | -- CMakeLists.txt
     | -- main.cpp
| -- build.bat
| -- CMakeLists.txt
```

##### 任务17 ：生成安装包

```
T17/
| -- bin
     | -- hello.exe
     | -- libhello.dll
| -- cmake
     | -- vInstallCpack.cmake
| -- include
     | -- dllexport.h
     | -- libhello.h
| -- lib
     | -- libhello.dll
     | -- libhello.lib
| -- build-for-unix-make.bat
| -- build-for-vs2010.bat
| -- CMakeLists.txt
```

参考：*[cpack打包生成安装包](https://blog.csdn.net/chengde6896383/article/details/80942906)*

##### 任务18 ：编译-部署-打包，生成安装包

```
T18/
| -- cmake
     | -- vInstallCpack.cmake
| -- include
     | -- dllexport.h
     | -- libhello.h
| -- src
     | -- CMakeLists.txt
     | -- libhello.cpp
| -- .gitignore
| -- build-for-unix-make.bat
| -- build-for-vs2010.bat
| -- CMakeLists.txt
| -- main.cpp
```

参考：*[cmake cpack 安装打包程序](https://www.cnblogs.com/smallredness/p/10938194.html)*
