# CMake 最低版本号要求
cmake_minimum_required(VERSION 2.8)

# 项目名称
project(demo)

# (1)添加一个 USE_MYMATH 选项，默认值为 ON
option(USE_MYMATH "Use provided math implementation" ON)

# (2)加入一个配置头文件 config.h，从 config.h.in 生成，使得可以通过预定义一些参数和变量来控制代码的生成
configure_file(
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_SOURCE_DIR}/config.h"
)
   
# (3)根据 USE_MYMATH 变量的值，来决定是否使用自己编写的 MathFunctions 库
if(USE_MYMATH)
  include_directories("${PROJECT_SOURCE_DIR}/math")
  add_subdirectory(math)
  set(EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)     # 附加 MathFunctions 到 EXTRA_LIBS 变量
endif(USE_MYMATH)

# 查找当前目录下的所有源文件，保存到变量 DIR_SRCS
aux_source_directory(. DIR_SRCS)

# 指定生成目标
add_executable(${PROJECT_NAME} ${DIR_SRCS})

# (4)添加链接库
if(USE_MYMATH)
  target_link_libraries(${PROJECT_NAME} ${EXTRA_LIBS})
endif()