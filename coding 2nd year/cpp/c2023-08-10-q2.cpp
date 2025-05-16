#include <bits/stdc++.h>
#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    unordered_map<int, int> map;
    vector<int> result;
    vector<vector<int>> vec;
    for (int i = 0; i < arr.size(); i++)
        if (map.find(s - arr[i]) != map.end())
        {
            result.push_back(min(arr[i], s - arr[i]));
            result.push_back(max(arr[i], s - arr[i]));
            vec.push_back(result);
            cout << "Printing" << endl;
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << '\t';
            cout << "Done" << endl;
            result.clear();
        }
        else
            map.insert({arr[i], i});
    sort(vec.begin(), vec.end());
    // cout << "Printing" << endl;
    // for (int i = 0; i < vec.size(); i++)
    // {
    //     for (int j = 0; j < vec[i].size(); j++)
    //         cout << vec[i][j] << '\t';
    //     cout << endl;
    // }
    // cout << "Done" << endl;
    return vec;
}
int main()
{
    vector<int> a{2, -6, 2, 5, 2};
    vector<vector<int>> b;
    b = pairSum(a, 2);
    for (int i = 0; i < b.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
            cout << b[i][j] << '\t';
        cout << endl;
    }
}