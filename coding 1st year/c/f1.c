#include <stdio.h>
int fact(int x)
{
    int f = 1;
    for (int i = 1; i <= x; i++)
        f = f * i;
    printf("Factorial is:%d", f);
}
int main()
{
    int x;
    printf("Enter number:");
    scanf("%d", &x);
    fact(x);
    return 0;
}