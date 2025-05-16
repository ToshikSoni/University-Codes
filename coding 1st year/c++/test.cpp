#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
usning namespace std;
vector<vector<int>> findTriplets(vector<int> arr, int n, int K)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 2; i++)
    {
        if (i == 0 || i >= 0 && arr[i] != arr[i - 1])
        {
            int start = i + 1;
            int end = n - 1;
            while (start < end)
            {
                int sum = arr[i] + arr[start] + arr[end];
                if (sum == K)
                {
                    vector<int> temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[start]);
                    temp.push_back(arr[end]);
                    ans.push_back(temp);
                    while (start < end && arr[start] == arr[start + 1])
                        start++;
                    while (start < end && arr[end] == arr[end - 1])
                        end--;
                    start++;
                    end--;
                }
                else if (sum < K)
                {
                    start++;
                }
                else
                {
                    end--;
                }
            }
        }
    }
    return ans;
}