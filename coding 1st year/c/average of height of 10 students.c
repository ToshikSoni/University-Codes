#include <stdio.h> 
int main()
{
    float h=0,a;
    for (int i=0;i<10;i++)
    {
        printf("Enter Height:");
        scanf("%f",&a);
        h=h+a;
    }
    printf("Average Height:%f",h/10);
    return 0;
}