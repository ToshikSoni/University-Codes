#include <stdio.h>
int main()
{
    int a;
    printf("Enter year:");
    scanf("%d", &a);
    if (a % 4 == 0)
    {
        if (a % 100 == 0)
        {
            if (a % 400 == 0)
            {
                printf("Its a leap year");
            }
            else
            {
                printf("Its not a leap year");
            }
        }
        else
        {
            printf("Its a leap year.");
        }
    }
    else
    {
        printf("Its not a leap year");
    }
    return 0;
}