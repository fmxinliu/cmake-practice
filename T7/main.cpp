#include <stdio.h>
#include <stdlib.h>
#include "MathFunctions.h"
#include "hello.h"
#include "bye.h"

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        printf("Usage: %s base exponent \n", argv[0]);
        return 1;
    }

    sayHello();
    double base = atof(argv[1]);
    int exponent = atoi(argv[2]);
    double result = power(base, exponent);
    printf("%g ^ %d is %g\n", base, exponent, result);
    sayBye();
    
    return 0;
}