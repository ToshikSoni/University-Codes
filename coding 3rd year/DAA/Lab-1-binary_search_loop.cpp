#include <iostream>
#include <vector>
using namespace std;
int binarySearch(vector<int> arr, int target)
{
    int lower = 0, upper = arr.size(), result = -1;
    while (lower <= upper)
    {
        int mid = (lower + upper) / 2;
        if (arr[mid] == target)
        {
            result = mid;
            break;
        }
        else if (target < arr[mid])
            upper = mid - 1;
        else
            lower = mid + 1;
    }
    return result;
}
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cout << "Enter " << i + 1 << "th term: ";
        cin >> temp;
        arr.push_back(temp);
    }
    int ele;
    cout << "Enter element to search: ";
    cin >> ele;

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

    int result = binarySearch(arr, ele);
    if (result == -1)
        cout << "Element is not found in the array.";
    else
        cout << "Element found at index: " << result;
}