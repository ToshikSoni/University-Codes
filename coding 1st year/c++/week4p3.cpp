#include <iostream>
using namespace std;
class Employee
{
protected:
    int empno;
    string name, designation;
    Employee() {}
    Employee(int e, string n, string d)
    {
        empno = e;
        name = n;
        designation = d;
    }
};
class Qualification : public Employee
{
protected:
    bool ug = false, pg = false;
    int experience;
    Qualification() {}
    Qualification(int ex, bool u, bool p, int e, string n, string d) : Employee(e, n, d)
    {
        experience = ex;
        ug = u;
        pg = p;
    }
};
class Salary : public Qualification
{
public:
    Salary() {}
    Salary(int e, string n, string d, int ex, bool u, bool p) : Qualification(ex, u, p, e, n, d) {}
    int calcIncrement()
    {
        int incre = 0;
        if (ug == true)
            incre++;
        if (pg == true)
            incre++;
        if (experience == 1)
            incre++;
        else if (experience == 2)
            incre = incre + 2;
        else if (experience == 3)
            incre = incre + 3;
        else if (experience > 3 && experience < 6)
            incre = incre + 4;
        else
            incre = incre + 5;
        return incre;
    }
    void showData()
    {
        cout << "Employee Number: " << empno << endl
             << "Name: " << name << endl
             << "Designation: " << designation << endl
             << "Experience: " << experience << endl;
        if (ug == true)
            cout << "UG: Yes" << endl;
        else
            cout << "UG: No" << endl;
        if (pg == true)
            cout << "PG: Yes" << endl;
        else
            cout << "PG: No" << endl;
    }
};
int main()
{
    Salary s(1, "Toshik Soni", "Manager", 12, true, true);
    s.showData();
    cout << "Increment: " << s.calcIncrement() << "%" << endl;
}