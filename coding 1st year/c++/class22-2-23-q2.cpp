#include <iostream>
using namespace std;
class Parent
{
    int n;

public:
    Parent()
    {
        cout << "Parent constructor." << endl;
        n = 0;
    }
    virtual ~Parent()
    {
        cout << "Parent destructor." << endl;
    }
};
class Child : public Parent
{
public:
    Child()
    {
        cout << "Child constructor." << endl;
    }
    ~Child()
    {
        cout << "Child destructor." << endl;
    }
};
int main()
{
    Parent *ptr = new Child;
    delete ptr;
}