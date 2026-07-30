#include <iostream>
#include <vector>
using namespace std;
bool func(vector<int> &a, int n, int i, int sum, vector<vector<int>> &dp)
{
    if (i == n)
    {
        if (sum == 0)
            return true;
        return false;
    }
    if (dp[i][sum] != -1)
        return dp[i][sum];

    if (a[i] > sum)
        return dp[i][sum] = func(a, n, i + 1, sum, dp);

    bool takeNum = func(a, n, i + 1, sum - a[i], dp);
    bool dontTekeNum = func(a, n, i + 1, sum, dp);

    return dp[i][sum] = takeNum || dontTekeNum;
}
bool subsetSum(vector<int> &a, int sum)
{
    int n = a.size();
    int i;
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    return func(a, n, 0, sum, dp);
}
int main()
{
    vector<int> a = {1, 3, 4};
    int sum = 6;
    cout << subsetSum(a, sum);
    return 0;
}