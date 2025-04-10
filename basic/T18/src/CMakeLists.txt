# 预定义宏 
add_definitions(-D DLL_EXPORTS) 
  
# 生成链接库 
add_library(libhello SHARED libhello.cpp) # 动态 

if(MSVC)
    set(LIB_NAME "libhello")
    set(LIB_PATH ${PROJECT_BINARY_DIR})
    set(DLL_PATH ${PROJECT_BINARY_DIR})
else(MSVC)
    set(LIB_NAME "hello")
    set(LIB_PATH ${PROJECT_SOURCE_DIR}/lib)
    set(DLL_PATH ${PROJECT_SOURCE_DIR}/lib)
endif(MSVC)

# 指定链接库生成目录
set(LIBRARY_OUTPUT_PATH ${LIB_PATH}) # lib
set_target_properties(libhello PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${DLL_PATH}) # dll

# 指定链接库名字
set_target_properties(libhello PROPERTIES OUTPUT_NAME ${LIB_NAME})
