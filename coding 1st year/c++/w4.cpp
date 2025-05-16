#include <iostream>
using namespace std;
class Student
{
public:
    int id;
    char name[20];
    void get_data()
    {
        int static i = 101;
        id = i;
        cout << "Enter name of " << i << " id: ";
        gets(name);
        i++;
    };
};
int main()
{
    Student s[5];
    int k = 0;
    for (int i = 0; i < 5; i++)
        s[i].get_data();
    for (int j = 101; j <= 105; j++)
    {
        cout << "\nName of " << j << " id: " << s[k].name;
        k++;
    }
}