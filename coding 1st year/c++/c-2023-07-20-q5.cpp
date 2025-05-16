#include <iostream>
using namespace std;
int main()
{
    int size;
    cout << endl // deletion in array
         << "Enter size of array: ";
    cin >> size;
    int *arr3 = new int[size];
    cout << "Enter values in array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr3[i];
    }
    int index;
    cout << "Enter index to delete: ";
    cin >> index;
    int *temp = new int[size];
    for (int i = 0; i < size; i++)
    {
        temp[i] = arr3[i];
    }
    delete arr3;
    size--;
    arr3 = new int[size];
    for (int i = 0; i < size; i++)
    {
        if (i < index)
            arr3[i] = temp[i];
        else
            arr3[i] = temp[i + 1];
    }
    cout << endl
         << "printing arr3: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr3[i] << ' ';
    }
    delete temp;
}