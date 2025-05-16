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
    friend void operator-(Operator &a) // pre increment with friend function
    {
        a.x = (a.x - 1);
    }
    void show()
    {
        cout << "Value of x is: " << x << endl;
    }
};
int main()
{
    Operator a;
    a.get();
    -a;
    operator-(a);
    a.show();
}