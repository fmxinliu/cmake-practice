# Find<name>
# --------
# 预定义模块，一般定义以下变量：
#   • <name>_FOUND          - 是否查找到库
#   • <name>_INCLUDE_DIR    - 头文件路径
#   • <name>_LIBRARY        - 库文件lib
#=============================================

# 查找头文件
find_path(HELLO_INCLUDE_DIR libhello.h ../lib)

# 查找库
find_library(HELLO_LIBRARY libhello ../lib)
#find_library(HELLO_LIBRARY NAMES libhello PATHS ../lib)

# 查找成功置为True
if(HELLO_INCLUDE_DIR AND HELLO_LIBRARY)
    set(HELLO_FOUND TRUE)
endif(HELLO_INCLUDE_DIR AND HELLO_LIBRARY)

# 查找结果
if(HELLO_FOUND)
    if(NOT HELLO_FIND_QUIETLY) #find_package(HELLO QUIET)
        message(STATUS "Found Hello: ${HELLO_LIBRARY}") # lib
    endif(NOT HELLO_FIND_QUIETLY)
else(HELLO_FOUND)
    if(HELLO_FIND_REQUIRED) # find_package(HELLO REQUIRED)
        message(FATAL_ERROR "Could not find hello library") # 终止cmake
    endif(HELLO_FIND_REQUIRED)
endif(HELLO_FOUND)
