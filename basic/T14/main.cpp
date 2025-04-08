#include <stdio.h>
#include <stdlib.h>
#include "config.h" // CMake 根据 CMakeLists 配置文件中的设置自动生成

/**
 * power - Calculate the power of number.
 * @param base: Base value.
 * @param exponent: Exponent value.
 *
 * @return base raised to the power exponent.
 */
double power(double base, int exponent)
{
    int result = base;
    int i;

    if (exponent == 0)
    {
        return 1;
    }

    for(i = 1; i < exponent; ++i)
    {
        result = result * base;
    }
    
    return result;
}

int main(int argc, char *argv[])
{
    // print version info
    printf("Version: %s v%d.%d\n",
        argv[0],
        Demo_VERSION_MAJOR,
        Demo_VERSION_MINOR);
        
    if(argc < 3)
    {
        printf("Usage: %s base exponent \n", argv[0]);
        return 1;
    }
    
    double base = atof(argv[1]);
    int exponent = atoi(argv[2]);
    double result = power(base, exponent);
    printf("%g ^ %d is %g\n", base, exponent, result);
    
    return 0;
}
