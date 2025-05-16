#include <iostream>
using namespace std;
class Date
{
    int day, month, year;
    bool date = false, leap;

public:
    Date(int d, int m, int y)
    {
        if ((y >= 0) && (m <= 12 && m > 0) && (d <= 31 && d > 0))
        {
            if (y % 4 == 0)
            {
                if (y % 100 == 0)
                {
                    if (y % 400 == 0)
                        leap = true;
                    else
                        leap = false;
                }
                else
                    leap = true;
            }
            else
                leap = false;
            if (((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && d <= 31) || ((m == 4 || m == 6 || m == 9 || m == 11) && d <= 30) || (m == 2 && ((leap == true && d <= 29) || (leap == false && d <= 28))))
            {
                date = true;
                day = d;
                month = m;
                year = y;
            }
            else
                goto t;
        }
        else
        {
        t:
            cout << "Enter valid date." << endl;
        }
    }
    void displayDate()
    {
        if (date == true)
            cout << "The date is: " << day << "/" << month << "/" << year << endl;
        else
            cout << "Date is invalid." << endl;
    }
    void incrementDay()
    {
        if (date == true)
        {
            if (((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day == 31) || ((month == 4 || month == 6 || month == 9 || month == 11) && day == 30) || (month == 2 && ((leap == true && day == 29) || (leap == false && day == 28))))
            {
                if (month == 12)
                {
                    day = 1;
                    month = 1;
                    year++;
                }
                else
                {
                    day = 1;
                    month++;
                }
            }
            else
                day++;
        }
        else
            cout << "Date is invalid." << endl;
    }
};
int main()
{
    int a, b, c;
    cout << "Enter day month year: ";
    cin >> a >> b >> c;
    Date d(a, b, c);
    d.incrementDay();
    d.displayDate();
}