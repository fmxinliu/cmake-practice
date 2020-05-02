# 目标文件
#install(TARGETS hello libhello libhellostatic
#        RUNTIME DESTINATION bin
#        LIBRARY DESTINATION lib
#        ARCHIVE DESTINATION libstatic
#       )
  
# 非目标文件的可执行程序（当然也可以是目标文件的可执行程序)
#install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/*.pdb pdb)

# 普通文件的安装:
#install(FILES <files> DESTINATION <dir>)

# 目录的安装:
install(DIRECTORY include lib bin DESTINATION ..)
#===========================================================

# 设置包类型
set(CPACK_GENERATOR "ZIP")  

# 设置软件包版本
set(CPACK_PACKAGE_VERSION "1.0") 

# 设置软件包名称
set(CPACK_PACKAGE_NAME "hello")

# 设置软件包装位置
set(CPACK_SET_DESTDIR true)
set(CPACK_INSTALL_PREFIX "include")

# 设置软件包生成的位置
set(CPACK_OUTPUT_FILE_PREFIX ${CMAKE_CURRENT_SOURCE_DIR})

# 设置维护者信息
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "fmxinliu")

# 这一句放在CMakeLists.txt文件最后,不能少
include(CPack)
