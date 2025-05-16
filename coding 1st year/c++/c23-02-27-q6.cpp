#include <iostream>
using namespace std;
class Distance
{
    int feet;
    int inches;

public:
    Distance()
    {
        feet = 0;
        inches = 0;
    }
    Distance(int f, int i)
    {
        feet = f;
        inches = i;
    }
    friend ostream &operator>>(ostream &output, const Distance &D){}
    
};
int main()
{
}