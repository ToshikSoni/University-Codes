#include <stdio.h>
int main()
{
    float A,P,r,t;
    printf("initial prinicpal balance:");
    scanf("%f",&P);
    printf("annual intrest rate:");
    scanf("%f",&r);
    printf("time years:");
    scanf("%f",&t);
    A   = P*(1 + r*t);
    printf("amount %f",A);
    return 0;
}