#include <iostream>
#include <vector>
using namespace std;
int main()
{
    //by XOR
    vector<int> arr{1, 2, 3, 4, 5, 6, 8, 9, 10}, tempvec;
    int temp = 0, temp2 = 0, missing;
    for (int i = 1; i <= arr[arr.size() - 1]; i++)
        temp = temp ^ i;
    for (int i = 0; i < arr.size(); i++)
        temp2 = temp2 ^ arr[i];
    missing = (temp2 ^ temp);
    for (int i = 0; i < arr.size(); i++)
    {
        tempvec.push_back(arr[i]);
        if (arr[i] == missing - 1)
            tempvec.push_back(missing);
    }
    arr = tempvec;
    cout << "Missing element by XOR: " << missing << endl
         << "The completed vector is: ";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << '\t';
}