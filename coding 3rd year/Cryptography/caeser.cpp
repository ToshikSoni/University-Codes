#include <iostream>
using namespace std;
int main()
{
    string str;
    cout << "Enter the string: ";
    getline(std::cin, str);
    for (int i = 0; i < str.length(); i++)
        if ((str[i] < 65 || str[i] > 90) && (str[i] < 97 || str[i] > 122))
            continue;
        else if (str[i] == 'x')
            str[i] = 'a';
        else if (str[i] == 'y')
            str[i] = 'b'; 
        else if (str[i] == 'z')
            str[i] = 'c';
        else if (str[i] == 'X')
            str[i] = 'A';
        else if (str[i] == 'Y')
            str[i] = 'B';
        else if (str[i] == 'Z')
            str[i] = 'C';
        else
            str[i] += 3;
    cout << "Output string: " << str;
}