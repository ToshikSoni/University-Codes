#include <iostream>
using namespace std;
class Student
{
private:
    int roll_no;

protected:
    char course[10];

public:
    void get_rno();
    void show_rno();
};
class Result : public Student
{
private:
    int marks[3];

public:
    void get_data();
    int total();
    void display();
};
void Student::get_rno()
{
    cout << "Enter roll number: ";
    cin >> roll_no;
}
void Student::show_rno()
{
    cout << "\nRoll number: " << roll_no;
}
void Result::get_data()
{
    get_rno();
    cout << "Enter course: ";
    cin >> course;
    cout << "Enter marks in 3 subjects: ";
    cin >> marks[0] >> marks[1] >> marks[2];
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
    Result r;
    r.get_data();
    r.display();
}