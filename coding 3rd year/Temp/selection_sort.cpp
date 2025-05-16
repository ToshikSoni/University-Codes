#include <iostream>
#include <vector>
using namespace std;
void selection_sort(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int minIdx = i;
        for (int j = i; j < n; j++)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        swap(arr[minIdx], arr[i]);
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
    selection_sort(arr, n);
    cout << "Sorted array: ";
    for (auto x : arr)
        cout << x << ' ';
}