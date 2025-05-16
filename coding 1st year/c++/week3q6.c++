#include <iostream>
using namespace std;
class Test
{
    int a, b, *c;

public:
    void update(int x, int y, int z)
    {
        a = x;
        b = y;
        c = &z;
    }
    void show()
    {
        cout << "a:" << a << " b:" << b << " c:" << *c << endl;
    }
    Test(){};
    Test(Test &d)
    {
        a = d.a;
        b = d.b;
        c = d.c;
    }
};
int main()
{
    Test a;
    a.update(1, 2, 3);
    a.show();
    Test b = a;
    b.show();
    b.update(4, 5, 6);
    b.show();
    a.show();
}