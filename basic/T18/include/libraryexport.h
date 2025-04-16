#ifndef __LIBRARYEXPORT_H__
#define __LIBRARYEXPORT_H__


/* 检测编译器 */
#if defined(_MSC_VER)
    #define LIBRARY_COMPILER_MSVC
#elif defined(__GNUC__)
    #define LIBRARY_COMPILER_GCC
#endif


/* 定义导出 & 导入宏 */
#if defined(LIBRARY_SHARED) // 生成动态库
    #if defined(LIBRARY_COMPILER_MSVC)
        #if defined (DLL_EXPORTS_USE_DEF_FILE) // 使用def模块定义文件导出
            #define DLL_API
            #define LIBRARY_API_P
        #elif defined(LIBRARY_EXPORTS)
            #define LIBRARY_API __declspec(dllexport)
            #define LIBRARY_API_P
        #else
            #define LIBRARY_API __declspec(dllimport)
            #define LIBRARY_API_P
        #endif
    #elif defined(LIBRARY_COMPILER_GCC)
        #if __GNUC__ >= 4
            #define LIBRARY_API __attribute__((visibility ("default")))
            #define LIBRARY_API_P __attribute__((visibility ("hidden")))
        #else
            #define LIBRARY_API
            #define LIBRARY_API_P
        #endif
    #else
        #define LIBRARY_API
        #define LIBRARY_API_P
    #endif
#else // 生成静态库
    #define LIBRARY_API
    #define LIBRARY_API_P
#endif


/* 定义调用约定 */
#if defined(LIBRARY_SHARED) && defined(LIBRARY_COMPILER_MSVC)
    #define LIBRARY_CALL_CONVENTIONS __cdecl
#else
    #define LIBRARY_CALL_CONVENTIONS
#endif


/* 定义导出修饰符（用于C函数） */
#if defined(LIBRARY_SHARED) && defined(__cplusplus)
    #define LIBRARY_STYLE extern "C"
#else
    #define LIBRARY_STYLE
#endif


#endif // __LIBRARYEXPORT_H__
