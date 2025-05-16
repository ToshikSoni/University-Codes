#include <stdio.h>
#include <string.h>
void rev(char s[100])
{
    int a;
    a = strlen(s);
    for (int i = (a - 1); i >= 0; i--)
        printf("%c", s[i]);
}
void main()
{
    char a[100];
    printf("Enter string:");
    gets(a);
    rev(a);
}