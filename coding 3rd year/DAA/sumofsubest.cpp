#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void findSubsets(vector<int> &nums, int target, vector<vector<int>> &result, vector<int> &current, int index)
{
    if (target == 0)
    {
        result.push_back(current);
        return;
    }
    for (int i = index; i < nums.size(); ++i)
    {
        if (i > index && nums[i] == nums[i - 1])
            continue;
        if (nums[i] > target)
            break;
        current.push_back(nums[i]);
        findSubsets(nums, target - nums[i], result, current, i + 1);
        current.pop_back();
    }
}
vector<vector<int>> findSubsetsWithTargetSum(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    vector<int> current;
    findSubsets(nums, target, result, current, 0);
    return result;
}
int main()
{
    vector<int> nums = {1, 5, 11, 5};
    int target = 11;
    vector<vector<int>> result = findSubsetsWithTargetSum(nums, target);
    for (const auto &subset : result)
    {
        cout << "[";
        for (int num : subset)
            cout << num << " ";
        cout << "]" << endl;
    }
}