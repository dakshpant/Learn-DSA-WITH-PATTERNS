#include <iostream>
#include <vector>
using namespace std;
int binarySearch(vector<int> &a, int target)
{
    int n = a.size();
    int low = 0 ;
    int high = n - 1;
    while (low <= high)
    {
        int guess = (low + high) / 2;

        if (a[guess] == target)
            return guess;
        else if (a[guess] < target)
            low = guess + 1;
        else
        {
            high = guess - 1;
        }
    }
    return -1;
}
int main()
{
    vector<int> a = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    int ans = binarySearch(a, target);
    cout << ans << endl;
    return 0;
}