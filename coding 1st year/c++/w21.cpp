#include <iostream>
#include <string.h>
using namespace std;
class Exception
{
private:
    int errnum;
    string err_msg;

public:
    Exception(int en, string em)
    {
        errnum = en;
        err_msg = em;
    }
    void Display()
    {
        cout << errnum << err_msg;
    }
};
double division(int a, int b)
{
    if (b == 0)
    {
        throw Exception(007, "Division by zero condition!");
    }
    return (a / b);
}

int main()
{
    int x = 50;
    int y = 0;
    double z = 0;

    try
    {
        z = division(x, y);
        cout << z << endl;
    }
    catch (Exception e)
    {
        e.Display();
        // cout<<"a user defined exception";
    }

    return 0;
}
