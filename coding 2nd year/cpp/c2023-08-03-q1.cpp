#include <iostream>
using namespace std;
#include <vector>
int findDuplicate(vector<int> &arr)
{
    int temp = 0, temp2 = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        temp = temp ^ arr[i];
        if (i != arr.size() - 1)
            temp2 = temp2 ^ (i + 1);
        return temp ^ temp2;
    }
}
