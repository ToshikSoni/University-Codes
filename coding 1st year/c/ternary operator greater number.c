#include <stdio.h>
void main()
{
    int a = 5, b = 5;
    a == b ? printf("they are equal") : a > b ? printf("a is bigger")
                                              : printf("b is bigger");
}