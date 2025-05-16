#include <iostream>
using namespace std;
class A
{
public:
    virtual void show()
    {
        cout << "Show of A." << endl;
    }
};
class B : virtual public A
{
public:
    void show()
    {
        cout << "Show of B." << endl;
    }
};
class C : virtual public A
{
public:
    void show()
    {
        cout << "Show of C." << endl;
    }
};
class D : public B, public C
{
public:
    void show()
    {
        cout << "Show of D." << endl;
    }
};
int main()
{
    A *ptr, a;
    B b;
    C c;
    D d;
    ptr = &a;
    ptr->show();
    ptr = &b;
    ptr->show();
    ptr = &c;
    ptr->show();
    ptr = &d;
    ptr->show();
}