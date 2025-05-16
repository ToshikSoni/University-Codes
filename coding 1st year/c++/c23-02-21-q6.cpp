#include <iostream>
using namespace std;
class A
{
public:
    void virtual show()
    {
        cout << "A" << endl;
    }
};
class B : virtual public A
{
public:
    void show()
    {
        cout << "B" << endl;
    }
};
class C : virtual public A
{
public:
    void show()
    {
        cout << "C" << endl;
    }
};
class D : public B, public C
{
public:
    void show()
    {
        cout << "D";
    }
};
int main()
{
    A a;
    B b;
    C c;
    D d;
    A *ptr;
    ptr = &c;
    ptr->show();
}