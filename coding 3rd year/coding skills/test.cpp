#include <iostream>
#include <vector>
using namespace std;
long repeatedString(string s, long n)
{
    long num = 0;
    int i = 0;
    long temp = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'a')
            temp++;
    }
    if (s.length() >= n)
    {
        return temp;
    }
    else
    {
        long rem = n % s.length();
        int times = n / s.length();
        num += temp * times;
        for (int i = 0; i < rem; i++)
        {
            if (s[i] == 'a')
                num++;
        }
    }
    return num;
}

int main()
{
    repeatedString("a", 1000000000000);
}
