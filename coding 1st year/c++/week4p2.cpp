#include <iostream>
using namespace std;
class Student
{
protected:
    int roll_no;
    string name;

public:
    Student() {}
    Student(int r, string n)
    {
        roll_no = r;
        name = n;
    }
};
class Fees : protected Student
{
    int fees;

public:
    Fees() {}
    Fees(int f, int r, string n) : Student(r, n)
    {
        fees = f;
    }
    void submitFees()
    {
        cout << "Enter fees amount: ";
        cin >> fees;
        cout << "Fee amount has been submitted." << endl;
    }
    void generateReceipt()
    {
        cout << "Receipt has been generated for fees amount: " << fees << endl;
    }
};
class Result : protected Student
{
    int marks;
    char grade;
    bool flag = true;

public:
    Result() {}
    Result(int m, int r, string n) : Student(r, n)
    {

        if (marks > 100 || marks < 0)
        {
            flag = false;
            cout << "Enter correct marks." << endl;
        }
        else
            marks = m;
    }
    char showgrade()
    {
        if (flag == true)
        {
            if (marks == 100)
                grade = 'O';
            else if (marks >= 80)
                grade = 'A';
            else if (marks >= 60)
                grade = 'B';
            else if (marks >= 40)
                grade = 'C';
            else if (marks >= 20)
                grade = 'D';
            else if (marks >= 0)
                grade = 'E';
            return grade;
        }
        else
            return ' ';
    }
};
int main()
{
    Fees f(500, 1, "Toshik");
    Result r(21, 1, "Toshik");
    f.submitFees();
    f.generateReceipt();
    cout << "The grade is: " << r.showgrade();
}