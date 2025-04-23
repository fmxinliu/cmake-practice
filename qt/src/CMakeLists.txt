# 添加子目录，进一步Make
add_subdirectory(utils)
add_subdirectory(users)
add_subdirectory(config)

# 源文件
set(SRC_FILES
    main.cpp
    view/mainwindow.cpp
    view/mainwindow.h
    view/mainwindow.ui
    view/login.cpp
    view/login.h
    view/login.ui
)

# 生成可执行文件
add_executable(${PROJECT_NAME} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets users config)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/view)
