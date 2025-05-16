#include <iostream>
using namespace std;
class Ab
{
public:
    void virtual show() = 0;
};
class derived : public Ab
{
public:
    void show()
    {
        cout << "Show.";
    }
};
int main()
{
    derived a;
    a.show();
}