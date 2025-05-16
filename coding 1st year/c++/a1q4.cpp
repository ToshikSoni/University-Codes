#include <iostream>
using namespace std;
class Rectangle
{
    int length, width;

public:
    int area()
    {
        return length * width;
    }
    friend class Square;
};
class Square
{
    int side;

public:
    Square(int s)
    {
        side = s;
    }
    int area()
    {
        return side * side;
    }
    void setLW(Rectangle &t)
    {
        t.length = side;
        t.width = side;
    }
};
int main()
{
    Square s(5);
    Rectangle r;
    s.setLW(r);
    cout << "The area of a rectange with the same dimensions as the square: " << r.area();
}