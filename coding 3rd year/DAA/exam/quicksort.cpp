#include <iostream>
using namespace std;
int Partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j <= r - 1; j++)
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[j], arr[i]);
        }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}
void QuickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int pivot = Partition(arr, l, r);
        QuickSort(arr, l, pivot - 1);
        QuickSort(arr, pivot + 1, r);
    }
}
int main()
{
    int arr[] = {5, 2, 4, 1};
    QuickSort(arr, 0, 3);
    for (int i = 0; i < 4; i++)
        cout << arr[i] << " ";
}