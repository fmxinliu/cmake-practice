# 使用 QTranslator 加载 qm 文件

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

## 资源文件，加载 path 探讨
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