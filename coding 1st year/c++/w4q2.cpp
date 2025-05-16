#include <iostream>
using namespace std;
class Rectangle
{
    int length, breadth;

public:
    int area()
    {
        return (length * breadth);
    }
    Rectangle()
    {
        length = 0;
        breadth = 0;
    }
    Rectangle(int l, int b)
    {
        length = l;
        breadth = b;
    }
    Rectangle(int a)
    {
        length = a;
        breadth = a;
    }
};
int main()
{
    Rectangle r1;
    cout << "Area by no argument " << r1.area() << endl;
    Rectangle r2(5, 10);
    cout << "Area by two argument " << r2.area() << endl;
    Rectangle r3(4);
    cout << "Area by one argument " << r3.area() << endl;
}