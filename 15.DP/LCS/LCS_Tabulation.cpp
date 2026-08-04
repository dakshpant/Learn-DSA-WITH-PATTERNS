#include <iostream>
#include <vector>
using namespace std;
int lcs(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i < n; i++)
    {
        dp[i][m] = 0;
        for (int j = 0; j < m; j++)
        {
            dp[n][j] = 0;
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (s1[i] == s2[j])
                dp[i][j] = 1 + dp[i + 1][j + 1];
            else

                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
        }
    }
    return dp[0][0];
}
int main()
{
    string s1, s2;
    s1 = "abcde";
    s2 = "ace";
    cout << lcs(s1, s2);
    return 0;
}