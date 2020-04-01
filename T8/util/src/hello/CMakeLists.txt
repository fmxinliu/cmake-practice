# 查找当前目录下的所有源文件，保存到变量 DIR_HELLO_SRCS
aux_source_directory(. DIR_HELLO_SRCS)

# 生成链接库
add_library(HelloLib ${DIR_HELLO_SRCS})