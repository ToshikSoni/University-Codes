#include <iostream>
using namespace std;
class Operator
{
    int x;

public:
    void get()
    {
        cout << "Enter value of x: ";
        cin >> x;
    }
    void operator+(Operator &a) // with member function
    {
        x = x + a.x;
    }
    void show()
    {
        cout << "Value of x is: " << x << endl;
    }
};
int main()
{
    Operator a, b;
    a.get();
    b.get();
    a + b;
    a.show();
    a.operator+(b);
    a.show();
}