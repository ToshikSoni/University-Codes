#include <iostream>
using namespace std;
int main()
{
    int size;
    cout << endl // insertion in array
         << "Enter size of array: ";
    cin >> size;
    int *arr3 = new int[size];
    cout << "Enter values in array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr3[i];
    }
    int index, value;
    cout << "Enter index to insert: ";
    cin >> index;
    cout << "Enter value to inesert: ";
    cin >> value;
    int *temp = new int[size];
    for (int i = 0; i < size; i++)
    {
        temp[i] = arr3[i];
    }
    delete arr3;
    size++;
    arr3 = new int[size];
    for (int i = 0; i < size; i++)
    {
        if (i < index)
            arr3[i] = temp[i];
        else if (i == index)
            arr3[i] = value;
        else
            arr3[i] = temp[i - 1];
    }
    cout << endl
         << "printing arr3: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr3[i] << ' ';
    }
    delete temp;
}