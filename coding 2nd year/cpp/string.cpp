#include <iostream>
using namespace std;
void copy(string &a, string &b)
{
    a = b;
}
string conc(string &a, string &b)
{
    return a + b;
}
void append(string &a, string &b)
{
    a = a + b;
}
void append(string &a, char b)
{
    a = a + b;
}
int len(string &a)
{
    int count = 0;
    for (int i = 0; a[i] != '\0'; i++)
        count++;
    return count;
}
void rev(string &a)
{
    int first = 0, last = len(a) - 1;
    while (first <= last)
    {
        swap(a[first], a[last]);
        first++;
        last--;
    }
}
int ctoi(char a)
{
    return (int)a;
}
char itoc(int a)
{
    return (char)a;
}
string upper(string &str)
{
    string a = "";
    for (int i = 0; i < len(str); i++)
    {
        int val = ctoi(str[i]) - 32;
        if (val >= 65 && val <= 90)
            append(a, (char)val);
        else
            append(a, str[i]);
    }
    return a;
}
string lower(string &str)
{
    string a = "";
    for (int i = 0; i < len(str); i++)
    {
        int val = ctoi(str[i]) + 32;
        if (val >= 97 && val <= 122)
            append(a, (char)val);
        else
            append(a, str[i]);
    }
    return a;
}