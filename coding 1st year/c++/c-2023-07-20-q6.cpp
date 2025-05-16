#include <iostream>
using namespace std;
int main()
{
    int size; // searching
    cout << "Enter size of array: ";
    cin >> size;
    int arr2[size];
    cout << "Enter values in array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr2[i];
    }
    int value;
    cout<<"Enter value to search: ";
    cin>>value;
    cout<<"value found at index: ";
    for(int i=0;i<size;i++)
    {
        if(value==arr2[i])
            cout<<i<<' ';
    }
}