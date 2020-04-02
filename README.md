### C/C++ 编译规则文件

- C/C++ 程序写好之后，需要进行编译和链接，生成可执行文件，才能运行。
- 为了完成编译和链接，编译器需要知道一些规则。比如要编译的文件有哪些，使用什么编译选项，编译的中间文件和生成的可执行文件输出到哪个目录，生成的可执行文件叫什么名字等等。


- 为了提供这些规则，需要一个*编译规则文件*，比如 `Makefile` 、微软的 `vcxproj`。

### [CMake](https://baike.baidu.com/item/cmake/7138032?fr=aladdin) 编译配置工具

- 当然，可以进行手动编写*编译规则文件*。但不同编译器，遵循着不同的规范和标准，*编译规则文件*的语法也千差万别。这样，就带来了一个严峻的问题：如果更换编译器，就要重新编写*编译规则文件* 。比如：

  ​  ① 跨平台，为了保证软件能够在不同平台编译；

  ​  ②  windows 平台，从 `MinGw` 编译器 →  `MSVC` 编译器。

- 另一种，更简单的方法是：

  ​  ① 编写一种平台无关的 `CMakeLists.txt` 文件来定制编译流程；

  ​  ② 借助 `CMake` 工具，生成不同平台不同编译器，编译所需的 *编译规则文件* 。

### Make [构建工具](https://www.cnblogs.com/feng9exe/p/9225723.html)

- 按照*编译规则文件*描述的规则，编译、链接源文件，生成可执行文件，部署安装。 
- C/C++ 常用的 Make 工具，比如 [GNU Make](https://baike.baidu.com/item/make/17067703?fr=aladdin#1) ，QT 的 [qmake](http://qt-project.org/doc/qt-4.8/qmake-manual.html) ，微软的 [MS nmake](http://msdn.microsoft.com/en-us/library/ms930369.aspx) 。
