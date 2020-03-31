# 查找当前目录下的所有源文件，保存到变量 DIR_LIB_SRCS
aux_source_directory(. DIR_LIB_SRCS)

# 生成链接库
add_library(MathFunctions SHARED ${DIR_LIB_SRCS}) # 动态

# 预定义宏
add_definitions(-D WIN32)
add_definitions(-D Base_EXPORTS)

# 指定库文件生成目录
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/bin) # lib
set_target_properties(MathFunctions PROPERTIES RUNTIME_OUTPUT_DIRECTORY  ${PROJECT_SOURCE_DIR}/build/bin) # dll