# C++11标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 开启Qt自动编译
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# 查找UI模块
find_package(Qt5 COMPONENTS Widgets REQUIRED)

# 查找多语言模块
find_package(Qt5 COMPONENTS LinguistTools REQUIRED)


function(update_translations qm_files sources)
    set(ts_files ${ARGN})

    message("===param1==>" ${qm_files})
    message("===param2==>" ${sources})
    message("===param3==>" ${ts_files})

    # 查找多语言提取/生成工具
    find_program(LUPDATE_EXECUTABLE Qt5::lupdate)
    find_program(LRELEASE_EXECUTABLE Qt5::lrelease)

    # 更新 ts 文件
    execute_process(COMMAND ${LUPDATE_EXECUTABLE} ${sources} -ts ${ts_files})

    # 生成 qm 文件
    foreach(ts_file ${ts_files})
        get_filename_component(ts_file_name ${ts_file} NAME_WE)
        set(qm_file ${CMAKE_CURRENT_BINARY_DIR}/${ts_file_name}.qm)
        execute_process(COMMAND ${LRELEASE_EXECUTABLE} ${ts_file} -qm ${qm_file})
        list(APPEND ${qm_files} ${qm_file})
        message("===>" ${qm_file})
    endforeach()

    set(${qm_files} ${${qm_files}} PARENT_SCOPE)
endfunction()


function(make_translation_qrc qrc_file)
    set(qm_files ${ARGN})

    file(WRITE ${qrc_file} "<RCC>\n  <qresource prefix=\"/translations\">\n")
    foreach(qm_file ${qm_files})
        get_filename_component(qm_file_name ${qm_file} NAME)
        file(APPEND ${qrc_file} "    <file alias=\"${qm_file_name}\">${qm_file}</file>\n")
    endforeach()
    file(APPEND ${qrc_file} "</qresource>\n</RCC>")
endfunction()
