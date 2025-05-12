# C++11标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 开启Qt自动编译
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# 查找Qt版本
message(STATUS "Find Qt6...")
find_package(Qt6 COMPONENTS Core QUIET)

if(Qt6_FOUND)
    message(STATUS "Qt6 found at: ${Qt6_DIR}")
    message(STATUS "Using Qt6")
    set(QT_VERSION_MAJOR 6)
else()
    message(STATUS "Find Qt5...")
    find_package(Qt5 COMPONENTS Core QUIET)
    if(Qt5_FOUND)
        message(STATUS "Qt5 found at: ${Qt5_DIR}")
    else(Qt5_FOUND)
        find_package(Qt5Core QUIET)
        if(Qt5Core_FOUND)
            message(STATUS "Qt5Core found at: ${Qt5Core_DIR}")
            set(Qt5_0_FOUND True)
        endif(Qt5Core_FOUND)
    endif(Qt5_FOUND)

    if(Qt5_FOUND OR Qt5_0_FOUND)
        message(STATUS "Using Qt5")
        set(QT_VERSION_MAJOR 5)
    else()
        message(STATUS "Find Qt4...")
        find_package(Qt4 REQUIRED)
        message(STATUS "Using Qt4 (${QTVERSION})")
        set(QT_VERSION_MAJOR 4)
    endif()
endif()

# 查找Qt库
if(Qt4_FOUND)
    add_definitions(-DQ_NULLPTR=NULL)
    set(Qt Qt4::Qt)
    set(QtWidgets ${Qt}Gui)
else()
    set(Qt Qt${QT_VERSION_MAJOR}::)
    set(QtWidgets ${Qt}Widgets)

    set(Qt_FIND_COMPONENTS
        Widgets
        Gui
        Test
    )

    if(Qt5_0_FOUND)
        foreach(module ${Qt_FIND_COMPONENTS})
            find_package(Qt5${module} REQUIRED)
            set_property(TARGET Qt5::${module} PROPERTY
                INTERFACE_INCLUDE_DIRECTORIES ${Qt5${module}_INCLUDE_DIRS})
        endforeach()
    else()
        find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS ${Qt_FIND_COMPONENTS})
    endif()

    unset(Qt_FIND_COMPONENTS)
endif()

# 启用CTest（必须在顶层 CMakeLists.txt 中调用）
enable_testing()

# 包含自定义cmake宏
include("${CMAKE_CURRENT_LIST_DIR}/QtConfigExtras.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/QtMacros.cmake")
