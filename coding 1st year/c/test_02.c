#include <stdio.h>
int main()
{
    int c;
    printf("is:");
    scanf("%d", &c);
    (c < 10) ? printf("hi") : printf("bye");
    return 0;
}