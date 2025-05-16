#include <iostream>
using namespace std;
void swapAddress(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void swapReference(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
int main()
{
    int a = 10, b = 20;
    cout << "Before swap a: " << a << ", b: " << b << endl;
    swapAddress(&a, &b);
    cout << "After swap by address a: " << a << ", b: " << b << endl;
    int x = 10, y = 20;
    cout << "\nBefore swap x: " << x << ", y: " << y << endl;
    swapReference(x, y);
    cout << "After swap by reference x: " << x << ", y: " << y << endl;
}