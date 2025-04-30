#### Qt 工程结构

```
.
├── build_mingw.bat
├── build_unix.sh
├── build_vs.bat
├── cmake
│   ├── bulk_get_filename_component.cmake
│   └── qt.cmake
├── CMakeLists.txt
├── README.md
├── src
│   ├── CMakeLists.txt
│   ├── config
│   │   ├── CMakeLists.txt
│   │   ├── usermanager.cpp
│   │   └── usermanager.h
│   ├── main.cpp
│   ├── translations
│   │   ├── cmake_qt_en_US.ts
│   │   └── cmake_qt_zh_CN.ts
│   ├── users
│   │   ├── adduser.cpp
│   │   ├── adduser.h
│   │   ├── adduser.ui
│   │   ├── CMakeLists.txt
│   │   ├── modifyuser.cpp
│   │   ├── modifyuser.h
│   │   └── modifyuser.ui
│   ├── utils
│   │   ├── CMakeLists.txt
│   │   ├── configsaver.cpp
│   │   ├── configsaver.h
│   │   ├── namingrules.cpp
│   │   └── namingrules.h
│   └── view
│       ├── login.cpp
│       ├── login.h
│       ├── login.ui
│       ├── mainwindow.cpp
│       ├── mainwindow.h
│       └── mainwindow.ui
└── tests
    └── CMakeLists.txt
```