#include <stdio.h>
#include<conio.h>
int main()
{
    int a, b = 1, c = 0;
    printf("Enter number:");
    scanf("%d", &a);
    while (c < a)
    {
        c++;
        b *= c;
    }
    printf("The factorial is: %d", b);
    return 0;
}