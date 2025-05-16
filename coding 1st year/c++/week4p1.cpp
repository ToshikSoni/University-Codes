#include <iostream>
using namespace std;
class Employee
{
protected:
    int id;
    string name;

public:
    Employee() {}
    Employee(int i, string n)
    {
        id = i;
        name = n;
    }
};
class Salary : protected Employee
{
    int salary;

public:
    Salary() {}
    Salary(int s, int i, string n) : Employee(i, n)
    {
        salary = s;
    }
    void showData()
    {
        cout << "ID: " << id << endl
             << "Name: " << name << endl
             << "Salary: " << salary << endl;
    }
};
int main()
{
    int id, s;
    string n;
    Salary obj[3];
    for (int i = 0; i < 3; i++)
    {
        cout << endl
             << "Enter id of " << i + 1 << " employee: ";
        cin >> id;
        cin.ignore();
        cout << "Enter name of " << i + 1 << " employee: ";
        getline(cin, n);
        cout << "Enter salary of " << i + 1 << " employee: ";
        cin >> s;
        obj[i] = Salary(s, id, n);
    }
    for (int i = 0; i < 3; i++)
        obj[i].showData();
}