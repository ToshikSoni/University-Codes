#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
vector<int> findMedian(vector<vector<int>> &arr)
{
    vector<int> ans;
    int n = arr.size();
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i].size() % 2 == 0)
        {
            int temp = (arr[i][n / 2 - 1] + arr[i][n / 2]) / 2;
            ans.push_back(temp);
        }
        else
        {
            int temp = arr[i][n / 2];
            ans.push_back(temp);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
}