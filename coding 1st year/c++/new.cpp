#include <iostream>
using namespace std;
class DummyClass
{
    int num1, num2;
    int *ptr;

public:
    DummyClass()
    { // default constrcutor
        num1 = 0;
        num2 = 0;
        ptr = new int;
    }

    void setData(int x, int y, int z)
    {
        num1 = x;
        num2 = y;
        *ptr = z;
    }

    void showData()
    {
        cout << "A = " << num1 << " B = " << num2 << "*ptr=" << *ptr << endl;
    }

    // copy constructor -> it is responsible for deep copy.
    DummyClass(DummyClass &D)
    {
        num1 = D.num1;
        num2 = D.num2;
        ptr = new int;
        *ptr = *(D.ptr);
    }

    // destructor -> to deallocate memory consumed by new pointer ptr.
    ~DummyClass()
    {
        delete ptr;
    }
};

int main()
{
    DummyClass D1; // default constructor
    D1.setData(1, 2, 3);
    D1.showData();
    // Copy constructor declared above will came in action and do deep copy.
    DummyClass D2 = D1; // copy constructor
    D2.showData();
    D2.setData(4, 5, 6);
    D1.showData();
    D2.showData();
}