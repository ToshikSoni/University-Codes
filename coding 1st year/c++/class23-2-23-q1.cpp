#include <iostream>
using namespace std;
class Test
{
    int a;

public:
    Test()
    {
        cout << "constructor" << endl;
    }
    void dis()
    {
        cout << "display" << endl;
    }
    ~Test()
    {
        cout << "destructor" << endl;
    }
};
int main()
{
    Test *a;
    a->dis();
    cout << "a:" << a << endl;
    delete a;
    cout << "a:" << a << endl;
    a->dis();
    int b, *c;
    c = &b;
    cout << *c;
}