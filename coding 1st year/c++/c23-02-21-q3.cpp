#include <iostream>
using namespace std;
class Parent
{
public:
    void virtual show()
    {
        cout << "Parent." << endl;
    }
};
class Child : public Parent
{
public:
    void show()
    {
        cout << "Child." << endl;
    }
};
int main()
{
    Child c;
    c.show();
    Parent *ptr;
    Parent p;
    ptr = &p;
    ptr->show();
    ptr = &c;
    ptr->show();
}