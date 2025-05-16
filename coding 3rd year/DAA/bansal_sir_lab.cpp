#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &arr, int l, int m, int r)
{
    vector<int> t1, t2;
    for (int i = l; i <= m; i++)
    {
        t1.push_back(arr[i]);
    }
    for (int i = m; i < r; i++)
    {
        t2.push_back(arr[i]);
    }
    int i = l, j = m + 1, k = l;
    while (i < m && j < r)
    {
        if (t1[k] < t2[k])
        {
            arr[k] = t1[k];
            i++;
        }
        else
        {
            arr[k] = t2[k];
            j++;
        }
        k++;
    }
    while (i < m)
    {
        arr[k] = t1[k];
        i++;
    }
    while (j < r)
    {
        arr[k] = t2[k];
        j++;
    }
}
void mergesort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergesort(arr, 0, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
int main()
{
    vector<int> arr = {50, 21, 13, 13, 32, 13, 42, 23, 45, 7};
    mergesort(arr, 0, 9);
    for (auto x : arr)
    {
        cout << x << '\t';
    }
}