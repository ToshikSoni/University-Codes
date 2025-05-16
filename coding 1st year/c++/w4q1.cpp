#include <iostream>
using namespace std;
class Student
{
    string name;

public:
    void getName()
    {
        cout << "Enter name: ";
        getline(cin, name);
    }
    void showName()
    {
        if (name == "")
        {
            name = "Unknown";
            cout << "Name is: " << name << endl;
        }
        else
            cout << "Name is: " << name << endl;
    }
};
int main()
{
    Student a;
    a.getName();
    a.showName();
    a.getName();
    a.showName();
}