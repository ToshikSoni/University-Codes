#include <stdio.h>
int main()
{
    int i = 50;
    do
    {
        printf("%d\n", i);
        i--;
    } while (i > 0);
    i = 50;
    while (i > 0)
    {
        printf("%d\n", i);
        i--;
    }
    for (i = 50; i > 0; i--)
    {
        printf("%d\n", i);
    }
    return 0;
}