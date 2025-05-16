#include <stdio.h>
int main()
{
    printf("Enter your choice:");
    char c;
    scanf("%c", &c);
    int a[11], b, d, n, cou = 0, p;
    for (int i = 0; i < 10; i++)
    {
        printf("Enter values in array:");
        scanf("%d", &a[i]);
    }
    if (c == 'a' || c == 'A')
    {
        printf("Enter the element you want to search: ");
        scanf("%d", &n);
        for (int i = 0; i < 10; i++)
        {
            cou++;
            if (a[i] == n)
                printf("Element found. At location: %d\n", cou);
        }
    }
    else if (c == 'b' || c == 'B')
    {
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                if (a[i] < a[j])
                {
                    b = a[i];
                    a[i] = a[j];
                    a[j] = b;
                }
        printf("Ascending order ");
    }
    else if (c == 'c' || c == 'C')
    {
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                if (a[i] > a[j])
                {
                    b = a[i];
                    a[i] = a[j];
                    a[j] = b;
                }
        printf("Descending order ");
    }
    else if (c == 'd' || c == 'D')
    {
        printf("Enter element:");
        scanf("%d", &n);
        printf("Enter position(0-9):");
        scanf("%d", &p);
        for (int i = p; i < 11; i++)
        {
            b = a[i];
            a[i] = n;
            n = b;
        }
        d = 1;
    }
    else if (c == 'e' || c == 'E')
    {
        printf("Enter position of element(0-9): ");
        scanf("%d", &n);
        for (int i = n; i < 9; i++)
            a[i] = a[i + 1];
        d = 2;
    }
    printf("Array is: ");
    if (d == 1)
        for (int i = 0; i < 11; i++)
            printf("%d ", a[i]);
    else if (d == 2)
        for (int i = 0; i < 9; i++)
            printf("%d ", a[i]);
    else
        for (int i = 0; i < 10; i++)
            printf("%d ", a[i]);
    return 0;
}