#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr{1, 2, 3, 4, 5, 6, 8, 9, 10};
    vector<int> temp;
    int missing;
    for (int i = 0; i < arr.size(); i++)
    {
        temp.push_back(arr[i]);
        if (arr[i] != arr[i + 1] - 1 && i != arr.size() - 1)
        {
            missing = arr[i] + 1;
            temp.push_back(missing);
        }
    }
    arr = temp;
    cout << "Missing element: " << missing << endl
         << "The completed vector is: ";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << '\t';
}