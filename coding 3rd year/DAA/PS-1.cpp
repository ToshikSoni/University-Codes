#include <iostream>
#include <vector>
using namespace std;
int merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> tempa, tempb;
    for (int i = low; i <= mid; i++)
        tempa.push_back(arr[i]);
    for (int i = mid + 1; i <= high; i++)
        tempb.push_back(arr[i]);
    int i = 0, j = 0, k = low, count = 0;
    while (i < tempa.size() && j < tempb.size())
    {
        if (tempa[i] < tempb[j])
        {
            arr[k] = tempb[j];
            j++;
        }
        else
        {
            arr[k] = tempa[i];
            i++;
            count++;
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
    return count;
}
int mergeSort(vector<int> &arr, int low, int high)
{
    int count = 0;
    if (low < high)
    {
        int mid = (high + low) / 2;
        count += mergeSort(arr, low, mid);
        count += mergeSort(arr, mid + 1, high);
        count += merge(arr, low, mid, high);
    }
    return count;
}
int main()
{
    vector<int> arr = {5, 3, 7, 8, 1};
    cout << "Number of inversions: " << mergeSort(arr, 0, arr.size() - 1);
}