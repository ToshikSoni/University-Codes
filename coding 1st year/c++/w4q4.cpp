#include <iostream>
using namespace std;
class dynamic
{
    int a;

public:
    void get()
    {
        cout << "Enter value: ";
        cin >> a;
    }
};
int main()
{
    dynamic a = new dynamic[5];
}