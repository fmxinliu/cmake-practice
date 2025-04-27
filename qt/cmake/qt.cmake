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


function(MAKE_ABS_PATH _abs_files)
    foreach(_file ${ARGN})
        get_filename_component(_abs_file ${_file} ABSOLUTE)
        list(APPEND _abs_files ${_abs_file})
    endforeach()
    set(${_abs_files} ${${_abs_files}} PARENT_SCOPE)
endfunction()


function(UPDATE_TRANSLATIONS _qm_files _sources)
    # 转换为绝对路径
    make_abs_path(_ts_files ${ARGN})
    make_abs_path(_sources ${_sources})

    # 查找多语言提取/生成工具
    find_program(LUPDATE_EXECUTABLE lupdate REQUIRED)
    find_program(LRELEASE_EXECUTABLE lrelease REQUIRED)

    foreach(_ts_file ${_ts_files})
        # 更新 ts 文件
        get_filename_component(_ts_file_dir ${_ts_file} DIRECTORY)
        file(MAKE_DIRECTORY "${_ts_file_dir}")
        execute_process(COMMAND ${LUPDATE_EXECUTABLE} ${_sources} -ts ${_ts_file})

        # 生成 qm 文件
        get_filename_component(_ts_file_name ${_ts_file} NAME_WE)
        set(_qm_file ${CMAKE_CURRENT_BINARY_DIR}/${_ts_file_name}.qm)
        execute_process(COMMAND ${LRELEASE_EXECUTABLE} ${_ts_file} -qm ${_qm_file})

        list(APPEND ${_qm_files} ${_qm_file})
    endforeach()

    set(${_qm_files} ${${_qm_files}} PARENT_SCOPE)
endfunction()


function(MAKE_TRANSLATION_QRC _qrc_file)
    file(WRITE ${_qrc_file} "<RCC>\n  <qresource prefix=\"/translations\">\n")
    foreach(_qm_file ${ARGN})
        get_filename_component(_qm_file_name ${_qm_file} NAME)
        file(APPEND ${_qrc_file} "    <file alias=\"${_qm_file_name}\">${_qm_file}</file>\n")
    endforeach()
    file(APPEND ${_qrc_file} "</qresource>\n</RCC>")
endfunction()
