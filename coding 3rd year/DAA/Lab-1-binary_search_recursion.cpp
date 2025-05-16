#include <iostream>
#include <vector>
using namespace std;
void sort(vector<int> &arr, int n)
{
    while (true)
    {
        bool flag = true;
        for (int i = 0; i < n - 1; i++)
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                flag = false;
            }
        if (flag)
            break;
    }
}
int binarySearch(vector<int> arr, int lower, int upper, int ele)
{
    if (lower <= upper)
    {
        int mid = lower + (upper - lower) / 2;
        if (arr[mid] == ele)
            return mid;
        if (arr[mid] > ele)
            return binarySearch(arr, lower, mid - 1, ele);
        return binarySearch(arr, mid + 1, upper, ele);
    }
    return -1;
}
int main()
{
    int n;
    cout << "Enter number of terms: ";
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cout << "Enter " << i + 1 << "th element: ";
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr, n);
    int ele;
    cout << "Enter element to search: ";
    cin >> ele;
    int temp = binarySearch(arr, 0, n, ele);
    if (temp == -1)
        cout << "Element not found.";
    else
        cout << "Element found at index: " << temp + 1;
}