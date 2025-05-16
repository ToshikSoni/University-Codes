#include <iostream>
using namespace std;
class Test
{
    int x;

public:
    void get()
    {
        cout << "Enter the value of x: " << endl;
        cin >> x;
    }
    void show()
    {
        cout << "X= " << x << endl;
    }
    Test add(Test &t)
    {
        Test temp;
        temp.x = this->x + t.x;
        return temp;
    }
    friend Test operator+(Test &t1, Test &t2)
    {
        Test temp;
        temp.x = t1.x + t2.x;
        return temp;
    }
};
int main()
{
    Test o1, o2, o3;
    o1.get();
    o1.show();
    o2.get();
    o2.show();
    o3 = o1.add(o2);
    o3.show();
    o3 = o1 + o2;
    o3 = operator+(o2, o1);
    o3.show();
    // obj2=obj1+10; it is allowed
    // obj2=10+obj1; it is not allowed
    // it is allowed for friend function
    // "=" and "&" operator is already overloaded
    // ::,?/: ,.,sizeof cannot be overloaded
}