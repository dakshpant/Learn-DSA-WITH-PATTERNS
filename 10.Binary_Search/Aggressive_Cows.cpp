#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
bool func(vector<int> &stalls, int n, int k, int guess)
{
    int cows = 1;
    int pos = stalls[0];
    for (int i = 1; i < n; i++)
    {
        int dist = stalls[i] - pos;

        if (dist >= guess)
        {
            cows++;
            pos = stalls[i];
        }
        else
            continue;

        if (cows >= k)
            return true;
    }
    return false; // Couldn't place all k cows while maintaining at least 'guess' distance.
}
int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    int low = 1;                          // the min possible distance after placing 2 cows
    int high = stalls[n - 1] - stalls[0]; // the max possible dist by placing 2 cows which naturally is the last index - first
    int res = -1;

    while (low <= high)
    {
        int guess = (low + high) / 2;

        if (func(stalls, n, k, guess) == true)
        {
            res = guess;
            low = guess + 1;
        }
        else
            high = guess - 1;
    }
    return res;
}
int main()
{
    vector<int> stalls = {10, 1, 2, 7, 5};
    int k = 3;
    int ans = aggressiveCows(stalls, k);
    cout << ans << endl;
    return 0;
}