#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int func(vector<int> &nums, int n, int i, int prev, vector<vector<int>> &dp)
{
    if (i == n)
        return 0;
    if (dp[i][prev + 1] != -1)
        return dp[i][prev + 1];

    if (prev == -1 || nums[i] > nums[prev])
    {
        int take = 1 + func(nums, n, i + 1, i, dp);
        int notTake = func(nums, n, i + 1, prev, dp);
        return dp[i][prev+1] = max(take, notTake);
    }
    return dp[i][prev+1] = func(nums, n, i + 1, prev, dp);
}
int lis(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return func(nums, n, 0, -1, dp);
}
int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << lis(nums);
    return 0;
}