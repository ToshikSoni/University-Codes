#include <iostream>
using namespace std;
class Test
{
public:
    Test()
    {
        cout << "Default constructor called.";
    }
};
int main()
{
    Test a;
}