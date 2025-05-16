#include <iostream>
#include <exception>
using namespace std;
int main()
{
    try
    {
        int a, b;
        char c;
        cout << "Enter number 1, operator(+, -, /, *), number 2: " << endl;
        cin >> a >> c >> b;
        switch (c)
        {
        case '+':
            cout << "a+b: " << a + b;
            break;
        case '-':
            cout << "a-b: " << a - b;
            break;
        case '*':
            cout << "a*b: " << a * b;
            break;
        case '/':
            if (b != 0)
                cout << "a/b: " << a / b;
            else
                throw runtime_error("Divide by zero exception.");
            break;
        default:
            throw runtime_error("Invalid operator");
            break;
        }
    }
    catch (exception &e)
    {
        cerr << "Error is: " << e.what();
    }
}