#include <stdio.h>
void main()
{
    int n;
    printf("Enter number of terms:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < (n - i); j++)
            printf(" ");
        printf("1");

        if (i != 0)
            printf("1");
    }
}