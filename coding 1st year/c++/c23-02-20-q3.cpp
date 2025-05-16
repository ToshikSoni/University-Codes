#include <iostream>
#include <string.h>
using namespace std;
class Student
{
private:
    int roll_no;

protected:
    char course[10];

public:
    Student(int r, char *c)
    {
        roll_no = r;
        strcpy(course, c);
    }
    void show_rno();
};
class Result : public Student
{
private:
    int marks[3];

public:
    Result(int r, char *c, int m1, int m2, int m3) : Student(r, c)
    {
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }
    int total();
    void display();
};
void Student::show_rno()
{
    cout << "\nRoll number: " << roll_no;
}
int Result::total()
{
    int total = marks[0] + marks[1] + marks[2];
    return total;
}
void Result::display()
{
    show_rno();
    cout << "\nCourse: " << course << "\nMarks in 3 subjects: " << marks[0] << " " << marks[1]
         << " " << marks[2];
    cout << "\nTotal marks: " << total();
}
int main()
{
    Result r(321, (char *)"CPP", 10, 20, 30);
    r.display();
}