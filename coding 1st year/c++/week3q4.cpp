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
    void get()
    {
        cout << "Get a: ";
        cin >> a;
    }
};
int main()
{
    Test a;
    a.get();
    a.show();
    Test b = a;
    b.show();
}