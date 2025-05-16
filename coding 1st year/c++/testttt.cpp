#include <iostream>
#include <fstream>
using namespace std;
template <typename t1, typename t2, typename t3, typename t4, typename t5>
class Employee
{
    t1 name;
    t2 empid;
    t3 age;
    t4 sal;
    t5 department;

public:
    Employee(t1 n, t2 e, t3 a, t4 s, t5 d)
    {
        name = n;
        empid = e;
        age = a;
        sal = s;
        department = d;
    }
    void show()
    {
        cout << "name: " << name << "\tempid: " << empid << "\tage: " << age << "\tsal: " << sal << "department: "
             << department << endl;
    }
};
int main()
{
    Employee<string, int, int, int, string> e("Toshik Soni", 01, 18, 1500, "Hello");
    e.show();
}