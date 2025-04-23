set(module_name config)

# 源文件
set(SRC_FILES
    usermanager.cpp
    usermanager.h
)

# 生成链接库
add_library(${module_name} ${SRC_FILES})
target_link_libraries(${module_name} PRIVATE Qt5::Widgets utils)
target_include_directories(${module_name} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
