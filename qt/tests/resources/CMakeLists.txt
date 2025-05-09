set(IMG_FILE "${PROJECT_SOURCE_DIR}/src/images/app.ico")
set(IMG_QRC_FILE "${CMAKE_CURRENT_BINARY_DIR}/images.qrc") # 修改qrc生成位置（可选）
create_qrc_file(IMG_QRC_FILE "/images" "${IMG_FILE}")
add_qtest(tst_images_qrc "tst_images_qrc.cpp;${IMG_QRC_FILE}" Qt5::Gui)
target_compile_definitions(tst_images_qrc PRIVATE APP_ICON_PATH="${IMG_FILE}") # 传递变量，供代码使用


set(TS_FILES
    ${PROJECT_SOURCE_DIR}/src/translations/${PROJECT_NAME}_zh_CN.ts
    ${PROJECT_SOURCE_DIR}/src/translations/${PROJECT_NAME}_en_US.ts
)
update_translations(QM_FILES ${PROJECT_SOURCE_DIR}/src ${TS_FILES})

set(TR_QRC_FILE "${CMAKE_CURRENT_BINARY_DIR}/translations.qrc") # 修改qrc生成位置（可选）
create_qrc_file(TR_QRC_FILE "/translations" ${QM_FILES})
add_qtest(tst_translations_qrc "tst_translations_qrc.cpp;${TR_QRC_FILE}" Qt5::Core)
