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
    void operator+(Test &t)
    {
        cout << x + t.x << endl;
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
    o1 + o2;
    o1.operator+(o2);
}