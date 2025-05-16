#include <stdio.h>
void main()
{
    int a = 10;
    int *b;
    b = &a;
    printf("%d %d %d %d %d", a, &a, b, *b, &b);
}