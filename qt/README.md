#### Qt 工程结构

```
.
├── build_mingw.bat
├── build_unix.sh
├── build_vs.bat
├── cmake
│   ├── bulk_get_filename_component.cmake
│   └── qt.cmake
├── CMakeLists.txt
├── README.md
├── src
│   ├── CMakeLists.txt
│   ├── config
│   │   ├── CMakeLists.txt
│   │   ├── usermanager.cpp
│   │   └── usermanager.h
│   ├── images
│   │   └── app.ico
│   ├── main.cpp
│   ├── translations
│   │   ├── cmake_qt_en_US.ts
│   │   └── cmake_qt_zh_CN.ts
│   ├── users
│   │   ├── adduser.cpp
│   │   ├── adduser.h
│   │   ├── adduser.ui
│   │   ├── CMakeLists.txt
│   │   ├── modifyuser.cpp
│   │   ├── modifyuser.h
│   │   └── modifyuser.ui
│   ├── utils
│   │   ├── CMakeLists.txt
│   │   ├── configsaver.cpp
│   │   ├── configsaver.h
│   │   ├── namingrules.cpp
│   │   └── namingrules.h
│   └── view
│       ├── login.cpp
│       ├── login.h
│       ├── login.ui
│       ├── mainwindow.cpp
│       ├── mainwindow.h
│       └── mainwindow.ui
└── tests
    ├── config
    │   ├── CMakeLists.txt
    │   └── tst_usermanager.cpp
    ├── CMakeLists.txt
    ├── resources
    │   ├── CMakeLists.txt
    │   ├── tst_images_qrc.cpp
    │   └── tst_translations_qrc.cpp
    └── utils
        ├── CMakeLists.txt
        └── tst_usermanager.cpp
```