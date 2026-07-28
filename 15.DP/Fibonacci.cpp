#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<int, int> dp;
int fib(int n)
{
    if (n == 1 || n == 0)
        return n;
    if (dp.find(n) != dp.end())
        return dp[n];

    int a1 = fib(n - 1);
    int a2 = fib(n - 2);
    dp[n] = a1 + a2;
    return a1 + a2;
}
int main()
{
    int n = 60;
    cout << fib(n);
    return 0;
}