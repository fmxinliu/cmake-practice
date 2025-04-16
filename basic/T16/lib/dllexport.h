#ifndef __DLLEXPORT__H__
#define __DLLEXPORT__H__

#  if defined (DLL_EXPORTS)
#    define DLL_API __declspec (dllexport)
#  else
#    define DLL_API __declspec (dllimport)
#  endif

#endif