#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int a = 10, b = 20;
    cout << "Before Swapping: A = " << a << ", B = " << b << endl;
    a += b;    // a = 30
    b = a - b; // 30 - 20 => 10
    a -= b;    // 30 - 10 => 20
    cout << "After Swapping: A = " << a << ", B = " << b;
}