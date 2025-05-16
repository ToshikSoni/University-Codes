#include <iostream>
#include <fstream>
using namespace std;
class Student
{
    char section;
    string name;
    int age;

public:
    void get()
    {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter section: ";
        cin >> section;
        cout << "Enter age: ";
        cin >> age;
    }
    void show()
    {
        cout << endl
             << "Name: " << name << "\nAge: " << age << "\nSection: " << section << endl;
    }
    string setData()
    {
        return ("Name: ", name, "\tAge: ", age, "\tSection: ", section, "\n");
    }
};
int main()
{
    fstream fout;
    Student s, s1;
    s.get();
    fout.open("Student", ios::out | ios::binary);
    fout.write((char *)&s, sizeof(s));
    fout.close();
    fout.open("Student", ios::in | ios::binary);
    fout.read((char *)&s1, sizeof(s1));
    s1.show();
}