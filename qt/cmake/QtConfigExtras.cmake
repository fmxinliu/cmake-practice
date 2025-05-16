if (Qt5_0_FOUND AND WIN32)
    if (NOT CMAKE_VERSION VERSION_LESS 2.8.11 AND NOT Qt5_NO_LINK_QTMAIN)
        set(_isExe $<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>)
        set(_isWin32 $<BOOL:$<TARGET_PROPERTY:WIN32_EXECUTABLE>>)
        set(_isNotExcluded $<NOT:$<BOOL:$<TARGET_PROPERTY:Qt5_NO_LINK_QTMAIN>>>)
        set(_isPolicyNEW $<TARGET_POLICY:CMP0020>)
        get_target_property(_configs Qt5::Core IMPORTED_CONFIGURATIONS)
        set_property(TARGET Qt5::Core APPEND PROPERTY
            INTERFACE_LINK_LIBRARIES
                $<$<AND:${_isExe},${_isWin32},${_isNotExcluded},${_isPolicyNEW}>:Qt5::WinMain>
        )
        # For backward compatibility with CMake < 2.8.12
        foreach(_config ${_configs})
            set_property(TARGET Qt5::Core APPEND PROPERTY
                IMPORTED_LINK_INTERFACE_LIBRARIES_${_config}
                    $<$<AND:${_isExe},${_isWin32},${_isNotExcluded},${_isPolicyNEW}>:Qt5::WinMain>
            )
        endforeach()
        unset(_configs)
        unset(_isExe)
        unset(_isWin32)
        unset(_isNotExcluded)
        unset(_isPolicyNEW)
    endif()
endif()

if (Qt5Core_FOUND AND UNIX)
    if (Qt5Core_VERSION VERSION_GREATER_EQUAL "5.0" AND Qt5Core_VERSION VERSION_LESS "5.3")
        add_definitions(-fpermissive)
    endif()
endif()
