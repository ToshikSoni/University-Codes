#include <stdio.h>
void main()
{
    int a[3][3], b[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Enter in 1st array:");
            scanf("%d", &a[i][j]);
        }
    }
    for (int k = 0; k < 3; k++)
    {
        for (int l = 0; l < 3; l++)
        {
            printf("Enter in 2nd array:");
            scanf("%d", &b[k][l]);
        }
    }
    for (int m = 0; m < 3; m++)
    {
        for (int n = 0; n < 3; n++)
            a[m][n] = a[m][n] + b[m][n];
    }
    printf("Addition of array is:");
    for (int e = 0; e < 3; e++)
    {
        printf("\n| ");
        for (int f = 0; f < 3; f++)
        {
            printf("%d ", a[e][f]);
        }
        printf("|");
    }
}