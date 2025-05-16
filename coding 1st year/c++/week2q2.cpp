#include <iostream>
using namespace std;
class Meters;
class Kilometer
{
    int km;

public:
    void getKM()
    {
        cout << "Enter kilometers: ";
        cin >> km;
    }
    void totalDistance(Meters &obj);
};
class Meters
{
    int m;

public:
    void getM()
    {
        cout << "Enter meters: ";
        cin >> m;
    }
    friend void Kilometer::totalDistance(Meters &obj);
};
void Kilometer::totalDistance(Meters &obj)
{
    while (1)
    {
        if (obj.m >= 1000)
        {
            km++;
            obj.m = obj.m - 1000;
        }
        else
            break;
    }
    cout << "Distance covered: " << km << " Km " << obj.m << " m";
}
int main()
{
    Meters object1;
    Kilometer object2;
    object1.getM();
    object2.getKM();
    object2.totalDistance(object1);
    return 0;
}