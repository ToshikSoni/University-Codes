#include <stdio.h>
int factoril(int x)
{
    int f;
    if (x == 0)
    {
        return 1;
    }
    else
    {
        f = x * factoril(x - 1);
        return f;
    }
}
int main()
{
    int x;
    scanf("%d", &x);
    printf("%d", factoril(x));
    return 0;
}