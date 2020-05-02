# 预定义宏 
add_definitions(-D DLL_EXPORTS) 
  
# 生成链接库 
add_library(libhello SHARED libhello.cpp) # 动态 

# 指定库文件生成目录 
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib) # lib 
set_target_properties(libhello PROPERTIES RUNTIME_OUTPUT_DIRECTORY  ${PROJECT_SOURCE_DIR}/lib) # dll 
