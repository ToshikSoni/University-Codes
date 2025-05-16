#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &arr, int low, int mid1, int mid2, int high, vector<int> &res)
{
    int i = low, j = mid1, k = mid2, l = low;
    while ((i < mid1) && (j < mid2) && (k < high))
        if (arr[i] < arr[j])
            if (arr[i] < arr[k])
                res[l++] = arr[i++];
            else
                res[l++] = arr[k++];
        else
        {
            if (arr[j] < arr[k])
                res[l++] = arr[j++];
            else
                res[l++] = arr[k++];
        }
    while ((i < mid1) && (j < mid2))
        res[l++] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];
    while ((j < mid2) && (k < high))
        res[l++] = (arr[j] < arr[k]) ? arr[j++] : arr[k++];
    while ((i < mid1) && (k < high))
        res[l++] = (arr[i] < arr[k]) ? arr[i++] : arr[k++];
    while (i < mid1)
        res[l++] = arr[i++];
    while (j < mid2)
        res[l++] = arr[j++];
    while (k < high)
        res[l++] = arr[k++];
}
void mergeSort(vector<int> &arr, int low, int high, vector<int> &res)
{
    if (high - low < 2)
        return;
    int mid1 = low + ((high - low) / 3);
    int mid2 = low + 2 * ((high - low) / 3) + 1;
    mergeSort(res, low, mid1, arr);
    mergeSort(res, mid1, mid2, arr);
    mergeSort(res, mid2, high, arr);
    merge(res, low, mid1, mid2, high, arr);
}
int main()
{
    vector<int> arr = {5, 6, 4, 8, 3, 1};
    vector<int> res(arr);
    mergeSort(res, 0, arr.size(), arr);
    for (int num : res)
        cout << num << " ";
}