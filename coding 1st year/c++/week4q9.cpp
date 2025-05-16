#include <iostream>
using namespace std;
class Base
{
    int *arr = new int[100], temp;

public:
    int operator[](int index)
    {
        return arr[index];
    }
    void get_data()
    {
        cout << "Enter size of array: ";
        cin >> temp;
        cout << "Enter values in array: " << endl;
        for (int i = 0; i < temp; i++)
        {
            cin >> arr[i];
        }
    }
    void show_data()
    {
        cout << "The values in array are: " << endl;
        for (int i = 0; i < temp; i++)
        {
            cout << arr[i] << endl;
        }
    }
};
int main()
{
    Base b;
    b.get_data();
    b.show_data();
    cout << endl
         << b[2] << endl;
}