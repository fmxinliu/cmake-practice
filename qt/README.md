# cmake-qt
演示通过 cmake 管理 qt 工程，实现项目开发、单元测试、多语言翻译。

| Qt     | MinGW    | MSVC     | x86_64-linux-gnu |
|:------:|:--------:|:--------:|:--------:|
| 4.8.7  |          | &#x2705; |          |
| 5.0.0  |          | &#x2705; |          |
| 5.1.0  |          | &#x2705; |          |
| 5.9.9  | &#x2705; | &#x2705; | &#x2705; |
| 6.8.3  | &#x2705; | &#x2705; |          |


## 工程结构
```
.
├── CMakeLists.txt
├── cmake
│   ├── QtConfig.cmake
│   ├── QtConfigExtras.cmake
│   └── QtMacros.cmake
├── src
│   ├── CMakeLists.txt
│   ├── main.cpp
│   ├── config/
│   ├── images/
│   ├── translations/
│   ├── users/
│   ├── utils/
│   └── view/
└── tests
    ├── CMakeLists.txt
    ├── config/
    ├── resources/
    └── utils/
```

## 切换Qt版本编译

- Windows VS 环境，修改 [BuildConfig.bat](../BuildConfig.bat) 中如下变量，双击 [build_vs.bat](build_vs.bat)
```
@ set qt_vs_bin_dir=C:\DevEnv\Qt\5.0.0\5.0.0\msvc2010\bin
@ set qt_vs_build_exe=C:\Program Files (x86)\Microsoft Visual Studio 10.0\Common7\IDE\devenv.com
@ set qt_vs_generator="Visual Studio 10 2010"
```

- Windows MinGW 环境，修改 [BuildConfig.bat](../BuildConfig.bat) 中如下变量，双击 [build_mingw.bat](build_mingw.bat)
```
@ set qt_mingw_bin_dir=C:\DevEnv\Qt\6.8.3\6.8.3\mingw_64\bin
@ set qt_mingw_tools_dir=C:\DevEnv\Qt\6.8.3\Tools\mingw1310_64\bin
@ set qt_mingw_make_exe=mingw32-make.exe
```

- Unix 环境，修改 [build_unix.sh](build_unix.sh) 中的 PATH，执行`bash build_unix.sh`
```
PATH=~/Qt5.9.9/5.9.9/gcc_64/bin:$PATH
```

## 易错点

### 多语言翻译

- ts 文件中必须存在一条有效的翻译，这样生成的qm文件才能被正确加载，否则 QTranslator::load() 返回 false。
     ```
     <?xml version="1.0" encoding="utf-8"?>
     <!DOCTYPE TS>
     <TS version="2.1" language="zh_CN">
     <context>
     <name>MainWindow</name>
     <message>
          <location filename="mainwindow.ui" line="14"/>
          <source>MainWindow</source>
          <!-- 任意一条translation不为空，即可加载成功 -->
          <translation type="unfinished">主界面</translation> 
     </message>
     </context>
     </TS>
     ```

- 加载期间，必须确保 QTranslator 对象不会被提前释放，否则无法正确获取翻译。
     ```
     bool loadTranslation(const QString &qmPath)
     {
          QTranslator *translator = new QTranslator(qApp);
          bool ret = translator->load(qmPath);
          if (ret)
          {
               qDebug() << "Success to load translation file: " << qmPath;
               Q_ASSERT(qApp->installTranslator(translator));
          }
          else
          {
               qDebug() << "Failed to load translation file:" << qmPath;
          }

          return ret;
     }
     ```

### 资源文件加载路径
- 以相对路径方式指定文件时
  - 指定文件别名时，path为`:/前缀/文件别名`
  - 不指定文件别名时，path为`:/前缀/文件相对路径(删除相对路径中的..)`
- 以绝对路径方式指定文件时，必须给文件起别名，path为`:/前缀/文件别名`

**结论：** 向qrc添加文件时，建议指定文件别名。这样，当文件路径变化时，无需修改源代码。

**qrc文件路径描述**
```
D:/
 └── Test
     ├── qt
     │   ├── qm_loader
     │   │    ├── res.qrc
     │   │    ├── qm_loader_zh_CN_0.qm
     │   │    └── translations
     │   │         └── qm_loader_zh_CN_1.qm
     │   └── translations
     |        └── qm_loader_zh_CN_2.qm
     └── translations
          └── qm_loader_zh_CN_3.qm
```

**res.qrc**
```
<RCC>
    <qresource prefix="/">

        <!-- 1.以相对路径方式指定文件位置，不指定别名
            loadTranslation(":/qm_loader_zh_CN_0.qm");
            loadTranslation(":/translations/qm_loader_zh_CN_1.qm");
            loadTranslation(":/translations/qm_loader_zh_CN_2.qm");
            loadTranslation(":/translations/qm_loader_zh_CN_3.qm");
        
        <file>qm_loader_zh_CN_0.qm</file>
        <file>translations/qm_loader_zh_CN_1.qm</file>
        <file>../translations/qm_loader_zh_CN_2.qm</file>
        <file>../../translations/qm_loader_zh_CN_3.qm</file> -->
 
        <!-- 2.以相对路径方式指定文件位置，指定别名
            loadTranslation(":/qm_loader_zh_CN_0.qm");
            loadTranslation(":/qm_loader_zh_CN_1.qm");
            loadTranslation(":/qm_loader_zh_CN_2.qm");
            loadTranslation(":/qm_loader_zh_CN_3.qm");
         -->
        <file alias="qm_loader_zh_CN_0.qm">qm_loader_zh_CN_0.qm</file>
        <file alias="qm_loader_zh_CN_1.qm">translations/qm_loader_zh_CN_1.qm</file>
        <file alias="qm_loader_zh_CN_2.qm">../translations/qm_loader_zh_CN_2.qm</file>
        <file alias="qm_loader_zh_CN_3.qm">../../translations/qm_loader_zh_CN_3.qm</file>


        <!-- 3. 以绝对路径方式指定文件位置，必须指定别名
            loadTranslation(":/qm_loader_zh_CN_0.qm");
            loadTranslation(":/qm_loader_zh_CN_1.qm");
            loadTranslation(":/qm_loader_zh_CN_2.qm");
            loadTranslation(":/qm_loader_zh_CN_3.qm");
         
        <file alias="qm_loader_zh_CN_0.qm">D:/Test/qt/qm_loader/qm_loader_zh_CN_0.qm</file>
        <file alias="qm_loader_zh_CN_1.qm">D:/Test/qt/qm_loader/translations/qm_loader_zh_CN_1.qm</file>
        <file alias="qm_loader_zh_CN_2.qm">D:/Test/qt/translations/qm_loader_zh_CN_2.qm</file>
        <file alias="qm_loader_zh_CN_3.qm">D:/Test/translations/qm_loader_zh_CN_3.qm</file> -->

    </qresource>
</RCC>
```