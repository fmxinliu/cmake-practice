#### MSVC生成静态库，不需要修饰
- 生成库时，如果添加了 __declspec(dllexport)，不影响生成
- 导入库时，如果添加了 __declspec(dllimport)，会报错

#### MSVC生成动态库
- 生成库时，需要添加 __declspec(dllexport)
- 导入库时，需要添加 [__declspec(dllimport)](https://blog.csdn.net/qq_38297377/article/details/127280957)

#### MSVC通过def模块定义文件，生成动态库，不需要修饰
- 导入库时，如果引用了库中的类，再添加 __declspec (dllimport)，会报错

#### GCC生成静态库，不需要修饰
- 如果添加了__attribute__((visibility ("default")))，不影响生成
- 如果添加了__attribute__((visibility ("hidden")))，不影响生成

#### [GCC生成动态库，不需要修饰](https://blog.csdn.net/veryitman/article/details/46756683)
- 不添加修饰，默认全部符号可见
- 如果添加了__attribute__((visibility ("default")))，控制哪些符号可见
- 如果添加了__attribute__((visibility ("hidden")))，控制哪些符号不可见