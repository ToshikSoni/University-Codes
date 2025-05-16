#include <iostream>
using namespace std;
int main()
{
    char x = 128;
    x >>= 1;
    if (x)
        cout << "If condition: " << int(x) << endl;
    else
        cout << "Else condition: " << int(x) << endl;
    x <<= 2;
    if (x)
        cout << "If condition: " << int(x) << endl;
    else
        cout << "Else condition: " << int(x) << endl;
}