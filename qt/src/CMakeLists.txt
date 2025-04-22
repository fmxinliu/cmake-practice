# 源文件
set(SRC_FILES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    login.cpp
    login.h
    login.ui
)

# 生成可执行文件
add_executable(${PROJECT_NAME} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
