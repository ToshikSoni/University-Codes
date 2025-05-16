#include <stdio.h>
int main()
{
    int num = 0, i = 1;
    for (int i = 1; i < 51; i++) // by for
    {
        if (i % 7 == 0)
        {
            num = num + i;
        }
    }
    num = 0;
    do // by do while
    {
        if (i % 7 == 0)
        {
            num = num + i;
        }
        i++;
    } while (i < 51);
    i = 1, num = 0;
    while (i < 51) // by while
    {
        if (i % 7 == 0)
        {
            num = num + i;
        }
        i++;
    }
    printf("sum of all number divisible by 7:%d", num);
    return 0;
}