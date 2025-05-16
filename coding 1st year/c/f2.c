#include <stdio.h>
void swap(int, int);
int main()
{
    int a, b;
    printf("Enter 1st number:");
    scanf("%d", &a);
    printf("Enter 2nd number:");
    scanf("%d", &b);
    swap(a, b);
    return 0;
}
void swap(int x, int y)
{
    int a;
    a = x;
    x = y;
    y = a;
    printf("Swapped values are: %d, %d", x, y);
}