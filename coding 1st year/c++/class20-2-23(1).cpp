#include <iostream>
using namespace std;
class Base
{
private:
    int a = 1;

protected:
    int b = 2;

public:
    int c = 3;
    void show()
    {
        cout << "a: " << a << ", b: " << b << ", c: " << c << endl;
    }
};
class pvt : private Base
{
public:
    void show()
    {
        cout << "a is inaccisible here"
             << ", b: " << b << ", c: " << c << endl;
    }
};
class pro : protected Base
{
public:
    void show()
    {
        cout << "a is inaccisible here"
             << ", b: " << b << ", c: " << c << endl;
    }
};
class pub : public Base
{
public:
    void show()
    {
        cout << "a is inaccisible here"
             << ", b: " << b << ", c: " << c << endl;
    }
};
int main()
{
    Base a;
    pvt b;
    pro c;
    pub d;
    a.show();
    b.show();
    c.show();
    d.show();
}