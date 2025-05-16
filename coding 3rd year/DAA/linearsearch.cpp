#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, ele, res = -1;
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
    cout << "Enter element to search: ";
    cin >> ele;
    for (int i = 0; i < n; i++)
        if (arr[i] == ele)
            res = i;
    if (res == -1)
        cout << "Element not found.";
    else
        cout << "Element found at index: " << res + 1;
}