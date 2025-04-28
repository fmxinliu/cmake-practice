# 批量文件名处理函数
#   bulk_get_filename_component(
#     <输出变量名>
#     <文件1> [<文件2> ...]  # 无需引号
#     <组件类型>
#     [BASE_DIR <基目录>]    # 可选
#   )
function(bulk_get_filename_component OUT_VAR)
    # 参数检查
    if(ARGC LESS 3)
        message(FATAL_ERROR "At least 3 arguments required: output_var, files and component")
    endif()

    # 检查BASE_DIR参数
    list(FIND ARGN "BASE_DIR" base_dir_index)
    if(NOT base_dir_index EQUAL -1)
        math(EXPR required_arg_count "${base_dir_index} + 3")
        if(ARGC LESS ${required_arg_count})
            message(FATAL_ERROR "BASE_DIR must be followed by a directory path")
        endif()

        math(EXPR base_dir_value_index "${base_dir_index} + 1")
        list(GET ARGN ${base_dir_value_index} BASE_DIR)
        list(REMOVE_AT ARGN ${base_dir_index} ${base_dir_value_index})
    endif()

    # 获取组件类型
    list(LENGTH ARGN remaining_args_count)
    math(EXPR component_index "${remaining_args_count} - 1")
    list(GET ARGN ${component_index} COMPONENT)

    # 验证组件类型
    set(VALID_COMPONENTS DIRECTORY NAME EXT NAME_WE ABSOLUTE REALPATH LAST_EXTENSION NAME_WLE)
    list(FIND VALID_COMPONENTS "${COMPONENT}" valid_component)
    if(valid_component EQUAL -1)
        message(FATAL_ERROR "Invalid component: ${COMPONENT}\nValid components: ${VALID_COMPONENTS}")
    endif()

    # 获取文件列表
    if(component_index EQUAL 0)
        message(FATAL_ERROR "At least one file must be specified")
    endif()
    list(SUBLIST ARGN 0 ${component_index} FILES)

    # 处理文件
    set(result_list)
    foreach(file IN LISTS FILES)
        if(DEFINED BASE_DIR)
            get_filename_component(processed_item "${file}" ${COMPONENT} BASE_DIR "${BASE_DIR}")
        else()
            get_filename_component(processed_item "${file}" ${COMPONENT})
        endif()
        list(APPEND result_list "${processed_item}")
    endforeach()

    set(${OUT_VAR} "${result_list}" PARENT_SCOPE)
endfunction()


## 基本用法
#bulk_get_filename_component(dirs src/main.cpp DIRECTORY)
#message("----test---->${dirs}")

## 多个文件 list
#bulk_get_filename_component(names
#    "src/main.cpp;include/utils.h"
#    NAME_WE
#)
#message("----test---->${names}")

## 多个文件
#bulk_get_filename_component(names
#    src/main.cpp include/utils.h
#    NAME_WE
#)
#message("----test---->${names}")

## 带BASE_DIR
#bulk_get_filename_component(abs_paths
#    main.cpp ../tools src/lib.cpp
#    ABSOLUTE
#    BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR}
#)

#message("----test---->${abs_paths}")


#bulk_get_filename_component(var)  # 报错：至少需要3个参数
#bulk_get_filename_component(var file1.txt)  # 报错：必须指定组件类型
#bulk_get_filename_component(var file1.txt INVALID_TYPE)  # 报错：无效的组件类型
#bulk_get_filename_component(var file1.txt ABSOLUTE BASE_DIR)  # 报错：必须指定基目录路径
