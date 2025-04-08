# 指定生成目标
add_executable(hello main.cpp)

# 调用预定义在CMAKE_MODULE_PATH下的Find<name>.cmake模块
find_package(HELLO)

# 使用查找到的模块
if(HELLO_FOUND)
    include_directories(${HELLO_INCLUDE_DIR})
    target_link_libraries(hello ${HELLO_LIBRARY})
else(HELLO_FOUND)
    message(FATAL_ERROR "HELLO library not found")
endif(HELLO_FOUND)
