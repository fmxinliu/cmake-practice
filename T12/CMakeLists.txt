# CMake 最低版本号要求
cmake_minimum_required(VERSION 2.8)

# 项目名称
project(demo_test)

# 指定生成目标
add_executable(demo main.cpp)

# 启用测试
enable_testing()

# 测试程序是否成功运行
add_test(test_run demo 5 2)

# 测试帮助信息是否可以正常提示
add_test (test_usage demo)
set_tests_properties (test_usage PROPERTIES PASS_REGULAR_EXPRESSION "Usage: .* base exponent")
  
# 定义一个宏，用来简化测试工作
macro(do_test arg1 arg2 result)
  add_test(test_${arg1}_${arg2} demo ${arg1} ${arg2})
  set_tests_properties(test_${arg1}_${arg2} PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro(do_test)

# 使用该宏进行一系列的数据测试
do_test(5 2 "is 25")
do_test(10 5 "is 100000")
do_test(2 10 "is 1024")