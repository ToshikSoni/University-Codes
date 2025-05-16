#include <iostream>
#include <vector>
using namespace std;
void quicksort(vector<int> &arr, int left, int right)
{
    if (left >= right)
        return;
    int pivot = arr[left + (right - left) / 2], i = left, j = right;
    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
            swap(arr[i++], arr[j--]);
    }
    quicksort(arr, left, j);
    quicksort(arr, i, right);
}
int main()
{
    vector<int> arr = {3, 6, 8, 10, 1, 2, 1};
    quicksort(arr, 0, arr.size() - 1);
    for (int num : arr)
        cout << num << " ";
}