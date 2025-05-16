#include <iostream>
using namespace std;
class Test
{
public:
    Test()
    {
        cout << "Default constructor called." << endl;
    }
    ~Test()
    {
        cout << "Destructor called." << endl;
    }
};
int main()
{
    Test *obj = new Test();
    delete obj;
}