// program to convert decimal to binary octal and hexadecimal
#include <stdio.h>
int num(int n, int y)
{
    int c = 0, a[100];
    for (int i = 0; n >= 1; i++)
    {
        c = i;
        a[i] = n % y;
        n = n / y;
    }
    for (int i = c; i >= 0; i--)
    {
        if (a[i] < 10)
            printf("%d", a[i]);
        else
            printf("%c", a[i] - 10 + 'A');
    }
}
int main()
{
    int n;
    printf("Enter number:");
    scanf("%d", &n);
    printf("\nBinary is: ");
    num(n, 2);
    printf("\nOctal is: ");
    num(n, 8);
    printf("\nHexadecimal is: ");
    num(n, 16);
    return 0;
}