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
    void operator++(int)
    {
        x++;
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
    a.operator++(0);
    a.show();
}