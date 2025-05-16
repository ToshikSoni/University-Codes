#include <iostream>
using namespace std;
class Test
{
    Test()
    {
        cout << "Default constructor in private sector called." << endl;
    }

public:
    void static access()
    {
        Test object;
    }
};
int main()
{
    Test::access();
}