#include <iostream>
using namespace std;
class A
{
protected:
    void show()
    {
        cout << "In class A.";
    }
};
class B : protected virtual A
{
};
class C : virtual protected A
{
};
class D : public B, public C
{
public:
    void display()
    {
        show();
    }
};
int main()
{
    D o;
    o.display();
}