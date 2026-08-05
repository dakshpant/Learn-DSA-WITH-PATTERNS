#include <iostream>
#include <vector>
using namespace std;
int func(int n, int m, int i, int j,vector<vector<int>> &dp)
{
    if (i == n - 1 && j == m - 1)
        return 1;
        if(dp[i][j] != -1) return dp[i][j];
    if (i < 0 || i >= n || j < 0 || j >= m)
        return 0;
    
    return dp[i][j] =  func(n,m, i+1, j,dp)+func(n, m , i, j+1,dp);
}
int unique_paths(int n, int m)
{
     vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    return func(n, m, 0, 0, dp);
}
int main()
{
    int n = 3;
    int m = 7;
    cout<<unique_paths(n, m);
    return 0;
}