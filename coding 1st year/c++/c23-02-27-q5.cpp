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
    friend Operator operator+(Operator &a, Operator &b) // with friend function
    {
        Operator temp;
        temp.x = b.x + a.x;
        return temp;
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
    Operator d = a + b;
    Operator c = operator+(a, b);
    c.show();
    d.show();
}