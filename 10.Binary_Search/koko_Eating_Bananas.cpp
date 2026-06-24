#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int hourCalc(vector<int> &arr, int n, int speed)
{
    int hours = 0;
    for (int i = 0; i < n; i++)
    {
        hours = hours + arr[i] / speed;
        if (arr[i] % speed != 0)
            hours++;
    }
    return hours;
}

int koko(vector<int> &arr, int h)
{
    int n = arr.size();
    if(h < n) return -1;
    int maxi = arr[0];
    for (int i = 1; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
    }
    int low = 1;
    int high = maxi;
    int res = INT_MAX;

    while (low <= high)
    {
        int guess = (low + high) / 2;

        int hours = hourCalc(arr, n, guess);

        if (hours > h)
            low = guess + 1;
        else
        {
            res = guess;
            high = guess - 1;
        }
    }
    return res;
}
int main()
{
    vector<int> arr = {3, 6, 7, 11};
    int h = 8;
    int ans = koko(arr, h);
    cout << ans << endl;
    return 0;
}