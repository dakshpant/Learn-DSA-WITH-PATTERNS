#include <iostream>
#include <vector>
using namespace std;
int func(string s1, string s2, int n, int m, int i, int j, vector<vector<int>> &dp){
    if(i==n || j == m) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j]) return dp[i][j] = 1+func(s1, s2, n, m, i+1, j+1, dp);

    int c1 = func(s1, s2, n, m, i+1, j,dp);
    int c2 = func(s1, s2, n, m, i, j+1,dp);

    return dp[i][j] = max(c1, c2);
}
int lcs(string s1, string s2)
{
int n = s1.size();
int m = s2.size();
vector<vector<int>> dp(n+1,vector<int>(m+1, -1));
return func(s1,s2, n, m, 0, 0, dp);
}
int main()
{
    string s1, s2;
    s1 = "abcde";
    s2 = "ace";
    cout << lcs(s1, s2);
    return 0;
}