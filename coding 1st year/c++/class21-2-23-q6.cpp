#include <iostream>
using namespace std;
class A
{
public:
    void show()
    {
        cout << "A";
    }
};
class B : virtual public A
{
};
class C : virtual public A
{
};
class D : public B, public C
{
    public:
    void show()
    {
        cout<<"D";
    }
};
int main()
{
    D a;
    a.show();
}