#include <iostream>
#include <vector>
using namespace std;
int func(vector<int> &nums, int n, int i, int sum, vector<vector<int>> &dp)
{
    if (i == n)
    {
        if (sum == 0)
            return 1;
        return 0;
    }
    if (dp[i][sum] != -1)
        return dp[i][sum];

    if (sum < nums[i])
        return dp[i][sum] = func(nums, n, i + 1, sum, dp);

    int takeNum = func(nums, n, i + 1, sum - nums[i], dp);
    int dontTekeNum = func(nums, n, i + 1, sum, dp);
    return dp[i][sum] = takeNum + dontTekeNum;
}
int targetSum(vector<int> &nums, int target)
{
    int n = nums.size();
    int totalSum = 0;
    for (auto i : nums)
        totalSum += i;
    // if target + total sum is odd means it is not possible as cant divide into gropus equally
    if (totalSum + target % 2 != 0 || totalSum + target < 0)
        return 0;
    int sum = (target + totalSum) / 2; // sum of numbers in positive group
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));

    return func(nums, n, 0, sum, dp);
}
int main()
{
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    cout << targetSum(nums, target) << endl;
    return 0;
}