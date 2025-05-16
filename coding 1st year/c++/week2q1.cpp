#include <iostream>
using namespace std;
class Visitor
{
    static char name[30], mobile[10];
    int static vehicle, contact, id;

public:
    void getData();
    void showData();
};
int Visitor::id = 0, Visitor::vehicle, Visitor::contact;
char Visitor::name[30], Visitor::mobile[10];
void Visitor::getData()
{
    cout << "Enter name: ";
    gets(name);
    fflush(stdin);
    cout << "Enter mobile number: ";
    cin >> mobile;
    cout << "Enter vehicle registration number: ";
    cin >> vehicle;
    cout << "Enter contact id: ";
    cin >> contact;
    id++;
}
void Visitor::showData()
{
    cout << "\n\nID: " << id << "\nName: " << name << "\nMobile number: " << mobile << "\nVehicle registration number: " << vehicle << "\nEnter contact id: " << contact;
}
int main()
{
    static Visitor obj;
    obj.getData();
    obj.showData();
}