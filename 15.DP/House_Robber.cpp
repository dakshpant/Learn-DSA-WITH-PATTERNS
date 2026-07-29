#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int func(vector<int> &nums, int n, int i, int free, vector<vector<int>> &dp)
{
    if (i == n)
        return 0;

    // house arready visited ans robbed and memoized
    if (dp[i][free] != -1)
        return dp[i][free];

    // current house cant be robbed so noving to next with free=1
    if (free == 0)
        return dp[i][free] = func(nums, n, i + 1, 1, dp);

    // robbing current and skipping next
    int choice1 = nums[i] + func(nums, n, i + 1, 0, dp);
    // skipped curent so moving to next with free 1
    int choice2 = func(nums, n, i + 1, 1, dp);

    // choose the max combination of robbing and memoize it for later use
    return dp[i][free] = max(choice1, choice2);
}
int rob(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    int i = 0;
    int free = 1;
    return func(nums, n, i, free, dp);
}
int main()
{
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << rob(nums);
    return 0;
}