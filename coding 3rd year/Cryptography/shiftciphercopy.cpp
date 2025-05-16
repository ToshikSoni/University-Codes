#include <iostream>
#include <vector>
using namespace std;
string shiftbreak(string str, int k)
{
    k %= 27;
    for (int i = 0; i < str.length(); i++)
        if (str[i] + k > 'z')
        {
            int temp = 'z' - str[i];
            str[i] = 'a' + k - 1 - temp;
        }
        else
            str[i] = str[i] + k;
    cout << "Output string: " << k << ' ' << str << endl;
    return str;
}
int main()
{
    string str;
    cout << "Enter the string: ";
    getline(std::cin, str);
    for (int i = 0; i < 100; i++)
        shiftbreak(str, i);
}