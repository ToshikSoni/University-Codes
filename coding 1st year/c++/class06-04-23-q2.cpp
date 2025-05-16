#include <iostream>
using namespace std;
void sort(int arr[], int size)
{
    int temp;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}
void linearSearch(int arr[], int size, int ele)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == ele)
            cout << "Element found at index: " << i << endl;
}
void show(int arr[], int size)
{
    cout << "Elements are:" << endl;
    for (int i = 0; i < size; i++)
        cout << arr[i] << endl;
}
void binarySearch(int arr[], int size, int ele)
{
    sort(arr, size);
    cout << "Sorted array is:- " << endl;
    show(arr, size);
    int start = 0, end = size - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == ele)
        {
            cout << "Element found at index: " << mid << endl;
            break;
        }
        else if (arr[mid] < ele)
            start = mid + 1;
        else
            end = mid - 1;
    }
}
int *insertElement(int arr[], int &size, int ele, int index)
{
    int temp, *tarr;
    tarr = new int[size + 1];
    for (int i = 0; i < index; i++)
        tarr[i] = arr[i];
    tarr[index] = ele;
    for (int i = index; i <= size; i++)
        tarr[i + 1] = arr[i];
    size++;
    return tarr;
}
int *deleteElement(int arr[], int &size, int index)
{
    int temp, *tarr;
    tarr = new int[size - 1];
    for (int i = 0; i < index; i++)
        tarr[i] = arr[i];
    for (int i = index; i < size - 1; i++)
        tarr[i] = arr[i + 1];
    size--;
    return tarr;
}
void get(int arr[], int size)
{
    cout << "Enter elements:" << endl;
    for (int i = 0; i < size; i++)
        cin >> arr[i];
}
int main()
{
    int *arr, size;
    cout << "Enter size of array: ";
    cin >> size;
    arr = new int[size];
    get(arr, size);
    binarySearch(arr, size, 69);
}