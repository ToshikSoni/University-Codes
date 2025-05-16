#include <iostream>
#include <string.h>
using namespace std;
class Student
{
private:
    int roll_no;
    char name[20];
    int marks[3];
    int total(void); // function to compute total of the marks
public:
    void set_data(int r, char *n, int m1, int m2, int m3);
    void display_data(); // display roll no, name and total marks
};
inline int Student::total()
{
    int total = 0;
    for (int i = 0; i < 3; i++)
        total = total + marks[i];
    return total;
};
inline void Student::set_data(int r, char *n, int m1, int m2, int m3)
{
    roll_no = r;
    marks[0] = m1;
    marks[1] = m2;
    marks[2] = m3;
    strcpy(name, n);
};
inline void Student::display_data()
{
    cout << "Roll Number: " << roll_no << endl
         << "Name: " << name << endl
         << "Total Marks: " << total();
};
int main()
{
    Student a;
    int r, m1, m2, m3;
    char n[20];
    cout << "Enter roll number: ";
    cin >> r;
    cout << "Enter name: ";
    cin.ignore();
    gets(n);
    cout << "Enter marks in 3 subjects: ";
    cin >> m1 >> m2 >> m3;
    a.set_data(r, n, m1, m2, m3);
    a.display_data();
    return 0;
}