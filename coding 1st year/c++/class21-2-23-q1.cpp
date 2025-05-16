#include <iostream>
using namespace std;
class Student
{
    int roll_no;

public:
    void getRoll()
    {
        cout << "Enter roll number:";
        cin >> roll_no;
    }
    void showRoll()
    {
        cout << "Roll: " << roll_no;
    }
};
class Result : private Student
{
public:
    void getshow()
    {
        getRoll();
        showRoll();
    }
};
int main()
{
    Result a;
    a.getshow();
}