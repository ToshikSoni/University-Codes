#include <iostream>
using namespace std;
int main()
{
    // deletion by value
    int *arr, *temp, size, search, index;
    cout << "Enter size of array: ";
    cin >> size;
    arr = new int[size];
    temp = new int[size];
    cout << "Enter values in array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
        temp[i] = arr[i];
    }
    cout << "Enter value to search: ";
    cin >> search;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == search)
        {
            cout << "value found at index: " << i << endl;
            index = i;
            break;
        }
        if (i == size - 1)
        {
            exit(1);
        }
    }
    size--;
    delete arr;
    arr=new int[size];
    for (int i = 0; i < size; i++)
    {
        if (i < index)
            arr[i] = temp[i];
        else
            arr[i] = temp[i + 1];
    }
    cout << "Values of arr: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ' ';
    }
}