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


function(make_translation_qrc qrc_file)
    set(qm_files ${ARGN})

    file(WRITE ${qrc_file} "<RCC>\n  <qresource prefix=\"/translations\">\n")
    foreach(qm_file ${qm_files})
        get_filename_component(qm_file_name ${qm_file} NAME)
        file(APPEND ${qrc_file} "    <file alias=\"${qm_file_name}\">${qm_file}</file>\n")
    endforeach()
    file(APPEND ${qrc_file} "</qresource>\n</RCC>")
endfunction()
