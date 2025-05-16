#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> tempa, tempb;
    for (int i = low; i <= mid; i++)
        tempa.push_back(arr[i]);
    for (int i = mid + 1; i <= high; i++)
        tempb.push_back(arr[i]);
    int i = 0, j = 0, k = low;
    while (i < tempa.size() && j < tempb.size())
    {
        if (tempa[i] > tempb[j])
        {
            arr[k] = tempb[j];
            j++;
        }
        else
        {
            arr[k] = tempa[i];
            i++;
        }
        k++;
    }
    while (i < tempa.size())
    {
        arr[k] = tempa[i];
        i++;
        k++;
    }
    while (j < tempb.size())
    {
        arr[k] = tempb[j];
        j++;
        k++;
    }
}
void mergeSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int mid = (high + low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
int main()
{
    vector<int> arr = {54, 567, 567, 35, 24, 6, 68, 9, 7, 67, 35, 12, 46, 67, 678, 67, 234};
    mergeSort(arr, 0, arr.size() - 1);
    for (auto x : arr)
        cout << x << '\t';
}