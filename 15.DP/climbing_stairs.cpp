#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<int, int> dp;
int func(int i, int n)
{
    if (i == n)
        return 1;
    if (i > n)
        return 0; // means we are going out of bound

    if (dp.find(i) != dp.end())
        return dp[i];

    int a1 = func(i + 1, n);
    int a2 = func(i + 2, n);

    dp[i] = a1 + a2;
    return a1 + a2;
}
int climbingStairs(int n)
{
    return func(0, n);
}
int main()
{
    int n = 5;
    cout << climbingStairs(n);
    return 0;
}