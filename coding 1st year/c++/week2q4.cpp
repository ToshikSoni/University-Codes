#include <iostream>
using namespace std;
class Base
{
public:
    void printAddress()
    {
        cout << "Address of current object: " << this << endl;
    }
};
int main()
{
    Base obj1;
    obj1.printAddress();
    return 0;
} // Static member functions are not associated with any particular object,
  // so the this pointer would always be a null pointer.    