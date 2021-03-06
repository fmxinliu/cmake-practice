#ifndef LIBHELLO_H
#define LIBHELLO_H
#include <stdio.h>
#include "dllexport.h"

#define SAYHELLO_FUNC_DECLARATION \
extern "C" DLL_API void __stdcall sayHello()

SAYHELLO_FUNC_DECLARATION;

#endif
