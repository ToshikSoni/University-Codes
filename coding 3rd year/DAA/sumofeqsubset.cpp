#include <bits/stdc++.h>
using namespace std;
bool findPartition(vector<int> &arr)
{
    int n = arr.size();
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if (sum % 2 != 0)
        return false;
    vector<bool> dp(sum / 2 + 1, false);
    dp[0] = true;
    for (int i = 0; i < n; i++)
        for (int j = sum / 2; j >= arr[i]; j--)
            if (dp[j - arr[i]] == true || j == arr[i])
                dp[j] = true;
    return dp[sum / 2];
}
int main()
{
    vector<int> arr = {1, 5, 11, 3};
    cout << (findPartition(arr) ? "Yes" : "No");
}