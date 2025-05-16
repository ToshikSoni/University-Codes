#include <stdio.h>
struct student
{
    int sub[6];
    float perc;
    struct name
    {
        char first[20], middle[20], last[20];
    } nam;
};
void main()
{
    struct student s[5];
    int cou;
    float pe;
    for (int i = 0; i < 5; i++)
    {
        if (i == 0)
        {
            printf("\nEnter First name:");
            gets(s[i].nam.first);
            printf("Enter Middle name:");
            gets(s[i].nam.middle);
            printf("Enter Last name:");
            gets(s[i].nam.last);
        }
        else
        {
            gets(s[i].nam.first);
            printf("\nEnter First name:");
            gets(s[i].nam.first);
            printf("Enter Middle name:");
            gets(s[i].nam.middle);
            printf("Enter Last name:");
            gets(s[i].nam.last);
        }
        printf("Enter marks in 6 subjects:");
        for (int j = 0; j < 6; j++)
            scanf("%d", &s[i].sub[j]);
        cou = 0;
        for (int j = 0; j < 6; j++)
            cou = cou + s[i].sub[j];
        pe = cou / 6.0;
        s[i].perc = pe;
        printf("Percentage of %s %s %s is: %f", s[i].nam.first, s[i].nam.middle, s[i].nam.last, pe);
    }
}