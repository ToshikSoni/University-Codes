#include <iostream>
using namespace std;
template <typename T>
T area(T side)
{
    return side * side;
}
template <typename T>
T area(T length, T width)
{
    return length * width;
}
template <typename T>
T area(T radius, float pi)
{
    return pi * radius * radius;
}
int main()
{
    int side = 5, length = 4, width = 6;
    double radius = 3.5;
    cout << "Area of square: " << area(side) << endl
         << "Area of rectangle: " << area(length, width) << endl
         << "Area of circle: " << area(radius, (float)3.14) << endl;
}
