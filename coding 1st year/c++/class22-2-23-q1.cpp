#include <iostream>
using namespace std;
class Ab // abstract class
{
    virtual void show() = 0; // pure virtual function
};
class Child : protected Ab
{
public:
    void show()
    {
        cout << "Child class." << endl;
    }
};
int main()
{
    // Ab o; // we cannot create object of abstract class
    Child o;
    o.show();
}