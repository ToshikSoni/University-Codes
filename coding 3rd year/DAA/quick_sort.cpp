#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int> &arr, int low, int high)
{
     int pivot = arr[high];
    int j = low - 1;
    for (int i = low; i < high; i++)
        if (arr[i] < pivot)
        {
            j++;
            swap(arr[j], arr[i]);
        }
    swap(arr[j + 1], arr[high]);
    return j + 1;
}
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}
int main()
{
    vector<int> arr = {1, 3, 5, 2, 4};
    int n = arr.size();
    quickSort(arr, 0, n - 1);
    cout << "Sorted Array" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}