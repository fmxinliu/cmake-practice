set(module_name users)

# 源文件
set(SRC_FILES
    adduser.cpp
    adduser.h
    adduser.ui
    modifyuser.cpp
    modifyuser.h
    modifyuser.ui
)

# 生成静态库
add_library(${module_name} STATIC ${SRC_FILES})
target_link_libraries(${module_name} PRIVATE Qt5::Widgets utils config)
target_include_directories(${module_name} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
