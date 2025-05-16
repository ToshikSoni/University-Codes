#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int j = low - 1;
    for (int i = low; i < high; i++)
        if (arr[i] < pivot)
            swap(arr[++j], arr[i]);
    swap(arr[j + 1], arr[high]);
    return j + 1;
}
void quick_sort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}
int main()
{
    vector<int> arr;
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    quick_sort(arr, 0, n);
    cout << "Sorted array: ";
    for (auto x : arr)
        cout << x << ' ';
}