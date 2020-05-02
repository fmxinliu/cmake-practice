# 目录的安装:
install(DIRECTORY include lib bin DESTINATION ..)

# 当前时间
string(TIMESTAMP vTimeStamp "%Y%m%d%H%M%S")

# 当前分支
execute_process(
    COMMAND git rev-parse --abbrev-ref HEAD
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    OUTPUT_VARIABLE vGitBranch
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

# 最后一笔提交
execute_process(
    COMMAND git log -1 --format=%h
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    OUTPUT_VARIABLE vGitCommit
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

#===========================================================

# 设置安装包类型
set(CPACK_GENERATOR "ZIP")  

# 设置安装包版本
set(CPACK_PACKAGE_VERSION ${vGitBranch}-${vGitCommit}) 

# 设置安装包名称
set(CPACK_PACKAGE_NAME ${PROJECT_NAME})

# 设置安装包名字
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}")

# 设置安装包位置
set(CPACK_SET_DESTDIR true)
set(CPACK_INSTALL_PREFIX "include")

# 设置安装包生成的位置
set(CPACK_OUTPUT_FILE_PREFIX ${CMAKE_CURRENT_SOURCE_DIR})

# 设置维护者信息
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "fmxinliu")

# 这一句放在CMakeLists.txt文件最后,不能少
include(CPack)
