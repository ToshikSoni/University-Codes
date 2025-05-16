/*Program to divide two numbers in C.
Programmer: Harsh Shah, Date: 29/6/13*/

#include <stdio.h>
#include <conio.h>

void main()
{

    int one, two, div;

    printf("Enter first number - ");

    scanf("%d", &one);

    printf("Enter second number - ");

    scanf("%d", &two);

    div = one / two;

    printf("The divison of numbers %d and %d is %d", one, two, div);

    getch();
}
// End of the program.