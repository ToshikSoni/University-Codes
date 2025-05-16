#include <iostream>
#include <fstream>
using namespace std;
class Student
{
    int roll, fees;
    string name;

public:
    Student() {}
    Student(int r, int f, string n)
    {
        roll = r;
        fees = f;
        name = n;
    }
    void show()
    {
        cout << "Name: " << name << "\nRoll: " << roll << "\nFees: " << fees << endl
             << endl;
    }
};
int main()
{
    fstream file;
    int temp1, temp2, temp3;
    Student s1(1, 100, "Toshik"), s2(2, 200, "Wasfa"), s3(3, 300, "Kusum"), s4(4, 400, "Daddy"), s5;
    file.open("1file", ios::out | ios::binary);
    file.write((char *)&s1, sizeof(s1));
    file.write((char *)&s2, sizeof(s2));
    file.write((char *)&s3, sizeof(s3));
    file.seekp(0, ios::end);
    temp1 = file.tellp();
    cout << "Number of objects: " << temp1 / sizeof(s1) << endl;
    cout << "Enter index of object you want to edit: ";
    cin >> temp2;
    file.seekg(temp2 * sizeof(s1), ios::beg);
    file.write((char *)&s4, sizeof(s4));
    file.close();
    file.open("1file", ios::in | ios::binary);
    file.read((char *)&s5, sizeof(s1));
    s5.show();
    file.read((char *)&s5, sizeof(s1));
    s5.show();
    file.read((char *)&s5, sizeof(s1));
    s5.show();
    file.close();
}