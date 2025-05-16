#include <iostream>
using namespace std;
class Time
{
    int seconds = 0, minutes = 0, hours = 0;

public:
    Time(int s)
    {
        seconds = s;
        if (seconds >= 3600)
        {
            hours = seconds / 3600;
            seconds %= 3600;
            if (seconds >= 60)
                goto go;
        }
        else
        {
        go:
            minutes = seconds / 60;
            seconds %= 60;
        }
    }
    void operator++(int)
    {
        if (seconds == 59)
        {
            if (minutes == 59)
            {
                hours++;
                minutes = 0;
                seconds = 0;
            }
            else
            {
                minutes++;
                seconds = 0;
            }
        }
        else
            seconds++;
    }
    void operator--(int)
    {
        if (seconds == 0)
        {
            if (minutes == 0)
            {
                hours--;
                minutes = 59;
                seconds = 59;
            }
            else
            {
                minutes--;
                seconds = 59;
            }
        }
        else
            seconds--;
    }
    void show()
    {
        cout << "Time is:- " << hours << ":" << minutes << ":" << seconds << endl;
    }
};
int main()
{
    Time t(3600);
    t.show();
    t--;
    t.show();
    t++;
    t.show();
} 