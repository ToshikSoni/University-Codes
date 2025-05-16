#include <iostream>
using namespace std;
class B1;
class Base
{
    int a = 5;
    void friend hi(B1 &b)
    {
        cout << b.c;
    }
};
class B1
{
    int c = 10;
};
int main()
{
    Base b;
    hi(b);
}