#include <iostream>
using namespace std;
class Test
{
    int a;

public:
    void show()
    {
        cout << "Value of a:" << a << endl;
    }
    Test(int b)
    {
        a = b;
    }
    Test(Test &b)
    {
        cout << "\nCopy constructor called." << endl;
        a = b.a;
    }
};
int main()
{
    Test a(5);
    a.show();
    Test b = a;
    b.show();
}