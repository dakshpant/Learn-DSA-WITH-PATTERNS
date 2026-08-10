#include <iostream>
#include <vector>
using namespace std;
int func(vector<int> &prices, int n, int i, int k, vector<vector<int>> &dp)
{
    if (i == n)
        return 0;
    if (k == 0)
        return 0;

    if (dp[i][k] != -1)
        return dp[i][k];

    if (k % 2 == 0)
    {
        int bc1 = func(prices, n, i + 1, k - 1, dp) - prices[i];
        int bc2 = func(prices, n, i + 1, k, dp);
        return dp[i][k] = max(bc1, bc2);
    }
    else
    {
        int sc1 = func(prices, n, i + 1, k - 1, dp) + prices[i];
        int sc2 = func(prices, n, i + 1, k - 1, dp);
        return dp[i][k] = max(sc1, sc2);
    }
}
int buyAndSellStocks(vector<int> &prices, int k)
{
    int n = prices.size();
    k = k * 2;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    return func(prices, n, 0, k, dp);
}
int main()
{
    vector<int> prices = {2, 4, 1};
    int k = 2;
    cout << buyAndSellStocks(prices, k);
    return 0;
}