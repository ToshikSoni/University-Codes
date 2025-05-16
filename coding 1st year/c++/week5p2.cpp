#include <iostream>
using namespace std;
template <typename T>
T area(const T &x)
{
    return x * x;
}

template <typename T>
T area(const T &x, const T &y)
{
    return x * y;
}

template <typename T>
T area(const T &r)
{
    return M_PI * r * r;
}
int main()
{
    cout << "Area of square with side 5: " << area(5) << endl;
    cout << "Area of rectangle with sides 5 and 3: " << area(5, 3) << endl;
    cout << "Area of circle with radius 3: " << area(3.0) << endl;
    return 0;
}
