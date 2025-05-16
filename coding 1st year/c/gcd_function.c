#include <stdio.h>
int GCD(int n, int d)
{
    if (n > d)
        for (int i = (n - 1); i > 0; i--)
        {
            if (n % i == 0 && d % i == 0)
            {
                printf("%d", i);
                break;
            }
        }
    else if (n < d)
        for (int i = (d - 1); i > 0; i--)
        {
            if (n % i == 0 && d % i == 0)
            {
                printf("%d", i);
                break;
            }
        }
    else
        printf("%d", n);
}
void main()
{
    int n, d;
    printf("Enter 1st number:");
    scanf("%d", &n);
    printf("Enter 2nd number:");
    scanf("%d", &d);
    if (n < 1 || d < 1)
        printf("Enter number greater than 1.");
    else
    {
        printf("\nGCD: ");
        GCD(n, d);
    }
}