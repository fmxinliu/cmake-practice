set(module_name utils)

# 源文件
set(SRC_FILES
    configsaver.cpp
    configsaver.h
    namingrules.cpp
    namingrules.h
)

# 生成链接库
add_library(${module_name} ${SRC_FILES})
target_link_libraries(${module_name} PRIVATE Qt5::Widgets)

# 传递链接库头文件 -> 调用处
## 1.生成库的模块，调用target_include_directories()，将头文件路径和库绑定
## 2.引用库的模块，调用target_link_libraries()，链接库并包含库传递的头文件路径
target_include_directories(${module_name} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
