#include <iostream>
using namespace std;
int main()
{
    int size; // taking values from user
    cout << "Enter size of array: ";
    cin >> size;
    int arr2[size];
    cout << "Enter values in array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr2[i];
    }
    cout << endl
         << "printing arr2: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr2[i] << ' ';
    }
}