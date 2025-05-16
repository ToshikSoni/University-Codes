#include <iostream>
#include <vector>
using namespace std;
int main()
{
    //by sum of N natural number
    vector<int> arr{1, 2, 3, 4, 5, 6, 8, 9, 10}, tempvec;
    int sum = ((arr.size() + 1) * ((arr.size() + 1) + 1)) / 2, temp = 0, missing;
    for (int i = 0; i < arr.size(); i++)
        temp = temp + arr[i];
    missing = sum - temp;
    for (int i = 0; i < arr.size(); i++)
    {
        tempvec.push_back(arr[i]);
        if (arr[i] == missing - 1)
            tempvec.push_back(missing);
    }
    arr = tempvec;
    cout << "Missing element by sum of N: " << missing << endl
         << "The completed vector is: ";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << '\t';
}