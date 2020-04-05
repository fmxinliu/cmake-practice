#include <stdio.h>
#include <stdlib.h>
#include "config.h" // 预定义 HAVE_POW 的值，由 CMake 根据 CMakeLists 配置文件中的设置自动生成

#ifndef HAVE_POW
    #include "math/MathFunctions.h"
#else
    #include <math.h>
#endif

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        printf("Usage: %s base exponent \n", argv[0]);
        return 1;
    }

    double base = atof(argv[1]);
    int exponent = atoi(argv[2]);
    
#ifndef HAVE_POW
    printf("Now we use our own Math library. \n");    
    double result = power(base, exponent);
#else
    printf("Now we use the standard library. \n");
    double result = pow(base, exponent);
#endif
    printf("%g ^ %d is %g\n", base, exponent, result);

    return 0;
}