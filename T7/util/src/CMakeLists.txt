# 查找当前目录下的所有源文件，保存到变量 DIR_UTIL_SRCS
aux_source_directory(. DIR_UTIL_SRCS)

# 生成链接库
add_library(UtilLib ${DIR_UTIL_SRCS})