#include <iostream>
#include <vector>
using namespace std;
bool isPalindrome(int x)
{
    if (x < 0)
        return false;
    long result = 0;
    long temp = x;
    while (temp != 0)
    {
        int d = temp % 10;
        result = result * 10 + d;
        temp /= 10;
    }
    return (result == x);
}
int main()
{
    cout << isPalindrome(101);
}