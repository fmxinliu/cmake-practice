# 添加子目录，进一步Make
add_subdirectory(utils)
add_subdirectory(users)
add_subdirectory(config)

#######
set(TS_FILES
    translations/${PROJECT_NAME}_zh_CN.ts
    translations/${PROJECT_NAME}_en_US.ts
)

# 更新翻译文件
update_translations(QM_FILES . ${TS_FILES})
message("QM_FILES: ${QM_FILES}")

## 创建翻译 qrc 资源文件
create_qrc_file(TR_QRC_FILE "/translations" ${QM_FILES})
message("TR_QRC_FILE: ${TR_QRC_FILE}")

## 创建图片 qrc 资源文件
create_qrc_file(IMG_QRC_FILE "/images" "images/app.ico")
message("IMG_QRC_FILE: ${IMG_QRC_FILE}")

set(QRC_FILES ${TR_QRC_FILE} ${IMG_QRC_FILE})
#######

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
add_executable(${PROJECT_NAME} ${SRC_FILES} ${QRC_FILES} ${TS_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets users config)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/view)

# 去掉 console 控制台
set_target_properties(${PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE TRUE)
