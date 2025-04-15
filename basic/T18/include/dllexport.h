#ifndef __DLLEXPORT__H__
#define __DLLEXPORT__H__

#if defined(_MSC_VER)
#  if defined (DLL_EXPORTS)
#    define DLL_API __declspec(dllexport)
#  elif defined (DLL_EXPORTS_USE_DEF_FILE)
#    define DLL_API
#  else
#    define DLL_API __declspec(dllimport)
#  endif
#else
#    define DLL_API
#endif

// 函数调用规约
#if defined(_MSC_VER)
    #define DLL_CALL_CONVENTIONS __cdecl 
#else
    #define DLL_CALL_CONVENTIONS
#endif

// C语言风格
#ifdef __cplusplus
    #define DLL_STYLE extern "C" 
#else
    #define DLL_STYLE
#endif

#endif