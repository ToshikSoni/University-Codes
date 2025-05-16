#include <iostream>
using namespace std;
class AddAmount
{
    int amount = 50;

public:
    AddAmount(){}
    AddAmount(int a)
    {
        amount = amount + a;
    }
    void show()
    {
        cout << "The final amount is: " << amount << endl;
    }
};
int main()
{
    AddAmount a;
    a.show();
    AddAmount b(5);
    b.show();
}