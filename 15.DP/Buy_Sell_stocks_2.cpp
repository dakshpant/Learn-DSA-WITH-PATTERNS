#include <iostream>
#include <vector>
using namespace std;
int func(vector<int> &prices, int n, int i, int k, vector<vector<int>> &dp){
if(i == n) return 0;
if(k == 0) return 0;

if(dp[i][k] != -1) return dp[i][k];

if(k == 2){
    int bc1 = func(prices, n, i+1, k-1,dp) - prices[i];
    int bc2 = func(prices, n, i+1, k,dp);
    return dp[i][k] = max(bc1, bc2);
}
else{
    int sc1 = func(prices, n, i+1, 2, dp) + prices[i];
    int sc2 = func(prices, n, i+1, k-1, dp);
    return dp[i][k] = max(sc1, sc2);
}
}
int buyAndSellStocks(vector<int> &prices) {
    int n = prices.size();
    int k = 2;
    vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
    return func(prices, n, 0, k, dp);
}
int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << buyAndSellStocks(prices);
    return 0;
}