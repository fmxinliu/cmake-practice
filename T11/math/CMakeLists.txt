# 查找当前目录下的所有源文件，保存到变量 DIR_LIB_SRCS
aux_source_directory(. DIR_LIB_SRCS)

# 生成链接库
add_library(MathFunctions ${DIR_LIB_SRCS}) # 静态
#add_library(MathFunctions STATIC ${DIR_LIB_SRCS}) # 静态

# 指定 MathFunctions 库的安装路径
install(TARGETS MathFunctions DESTINATION bin)

# 指定 MathFunctions.h 的安装路径
install(FILES MathFunctions.h DESTINATION include)