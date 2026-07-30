#include <iostream>
#include <vector>
using namespace std;
int func(vector<int> &arr, int n, int i, int sum, vector<vector<int>> &dp)
{
    if (i == n)
    {
        if (sum == 0)
            return 1;
        return 0;
    }
    if (dp[i][sum] != -1)
        return dp[i][sum];

    if (sum < arr[i])
        return dp[i][sum] = func(arr, n, i + 1, sum, dp);

    int takeNum = func(arr, n, i + 1, sum - arr[i], dp);
    int dontTekeNum = func(arr, n, i + 1, sum, dp);

    return dp[i][sum] = takeNum + dontTekeNum;
}
int subsetSum(vector<int> &arr, int sum)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));

    return func(arr, n, 0, sum, dp);
}
int main()
{
    vector<int> arr = {1, 2, 3};
    int target = 4;
    cout << subsetSum(arr, target);
    return 0;
}