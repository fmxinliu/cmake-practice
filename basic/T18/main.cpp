#include <stdio.h>
#include "libhello.h"

int main()
{
    Person p(100);
    puts("++++++");
    printf("%s(id=%d):", p.getClassName(), p.getId());
    sayHello();
    puts("++++++");
    return 0;
}