#include <iostream>
using namespace std;
class timeHour
{
    int h;

public:
    void getHour()
    {
        cout << "Enter hours: ";
        cin >> h;
    }
    friend class timeMinute;
};
class timeMinute
{
    int m;

public:
    void getMinute()
    {
        cout << "Enter minutes: ";
        cin >> m;
    }
    void calcTimeTaken(timeHour t)
    {
        int temp = 1;
        temp = t.h * 60;
        temp = temp + m;
        cout << "Total time taken to cover distance: " << temp << " minutes";
    }
};
int main()
{
    timeHour h;
    timeMinute m;
    h.getHour();
    m.getMinute();
    m.calcTimeTaken(h);
}