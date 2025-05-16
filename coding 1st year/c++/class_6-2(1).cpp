#include <iostream>
using namespace std;
class Student
{
    static int id;
    int roll = 0;

public:
    static void showid();
    void showroll();
};
int Student::id = 1;
void Student::showid()
{
    cout << endl
         << "ID: " << id << endl;
    id++;
};
void Student::showroll()
{
    cout << "Roll: " << roll << endl;
    roll++;
};
int main()
{
    Student s, s1, s2;
    s.showid();
    s.showroll();
    s1.showid();
    s1.showroll();
    s2.showid();
    s2.showroll();
}