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

include(cmake/bulk_get_filename_component.cmake)

function(UPDATE_TRANSLATIONS _qm_files _sources)
    # 转换为绝对路径
    bulk_get_filename_component(_ts_files ${ARGN} ABSOLUTE)
    bulk_get_filename_component(_sources ${_sources} ABSOLUTE)

    # 查找多语言提取/生成工具
    find_program(LUPDATE_EXECUTABLE lupdate REQUIRED)
    find_program(LRELEASE_EXECUTABLE lrelease REQUIRED)

    foreach(_ts_file ${_ts_files})
        # 更新 ts 文件
        get_filename_component(_ts_file_dir ${_ts_file} DIRECTORY)
        file(MAKE_DIRECTORY "${_ts_file_dir}")
        execute_process(COMMAND ${LUPDATE_EXECUTABLE} ${_sources} -ts ${_ts_file}
            RESULT_VARIABLE _result
            OUTPUT_VARIABLE _output
            ERROR_VARIABLE _error
        )

        if (NOT _result EQUAL 0)
            message(FATAL_ERROR ${_output}${_error})
        endif()

        # 生成 qm 文件
        get_filename_component(_ts_file_name ${_ts_file} NAME_WE)
        set(_qm_dir "${CMAKE_CURRENT_BINARY_DIR}/translations")
        set(_qm_file ${_qm_dir}/${_ts_file_name}.qm)
        file(MAKE_DIRECTORY ${_qm_dir})
        add_custom_command(OUTPUT ${_qm_file}
            COMMAND ${LRELEASE_EXECUTABLE}
            ARGS ${_ts_file} -qm ${_qm_file}
            DEPENDS ${_ts_file} VERBATIM
        )

        list(APPEND ${_qm_files} ${_qm_file})
    endforeach()

    set(${_qm_files} ${${_qm_files}} PARENT_SCOPE)
endfunction()


function(CREATE_QRC_FILE _qrc_file _qrc_prefix)
    if(NOT _qrc_prefix MATCHES "^/[a-zA-Z]*$")
        message(FATAL_ERROR "_qrc_prefix: Value is \"${_qrc_prefix}\", Format needs: / followed by letter(s)")
    endif()

    if(DEFINED ${_qrc_file})
        get_filename_component(_qrc_abs_file ${${_qrc_file}} ABSOLUTE)
        get_filename_component(_qrc_dir ${_qrc_abs_file} DIRECTORY)
    else()
        set(_qrc_dir ${CMAKE_CURRENT_BINARY_DIR}${_qrc_prefix})
        set(_qrc_abs_file ${_qrc_dir}${_qrc_prefix}.qrc)
        set(${_qrc_file} ${_qrc_abs_file} PARENT_SCOPE)
    endif()

    file(MAKE_DIRECTORY ${_qrc_dir})

    list(APPEND qrc_line_list "<RCC>")
    list(APPEND qrc_line_list "  <qresource prefix=\"${_qrc_prefix}\">")
    foreach(_file ${ARGN})
        get_filename_component(_file_name ${_file} NAME)
        get_filename_component(_abs_file ${_file} ABSOLUTE)
        list(APPEND qrc_line_list "    <file alias=\"${_file_name}\">${_abs_file}</file>")
    endforeach()
    list(APPEND qrc_line_list "  </qresource>")
    list(APPEND qrc_line_list "</RCC>")

    string(REPLACE ";" "\n" _qrc_file_content "${qrc_line_list}")
    file(WRITE "${_qrc_abs_file}" ${_qrc_file_content})
endfunction()


# 查找QtTest模块
find_package(Qt5 COMPONENTS Test REQUIRED)

# 启用CTest（必须在顶层 CMakeLists.txt 中调用）
enable_testing()

function(ADD_QTEST _test_name _test_sources _test_lib)
    if(IS_ABSOLUTE ${TEST_BIN_DIR})
        set(_test_working_dir ${TEST_BIN_DIR})
    else()
        get_filename_component(_test_working_dir "${PROJECT_BINARY_DIR}/tests/${TEST_BIN_DIR}" ABSOLUTE)
    endif()

    add_executable(${_test_name} ${_test_sources})
    target_link_libraries(${_test_name} PRIVATE Qt5::Test ${_test_lib})
    set_target_properties(${_test_name} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${_test_working_dir}"
    )
    add_test(
        NAME                ${_test_name}
        COMMAND             ${_test_name}
        WORKING_DIRECTORY   ${_test_working_dir}
    )
endfunction()
