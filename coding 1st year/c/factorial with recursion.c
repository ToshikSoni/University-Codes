#include <stdio.h>
int fact(int x)
{
    int fac = 1;
    if (x == 1)
        return 1;
    else
    {
        fac = x * fact(x - 1);
        return fac;
    }
}
int main()
{
    int x;
    printf("Enter number:");
    scanf("%d", &x);
    printf("Factorial is: %d", fact(x));
    return 0;
}