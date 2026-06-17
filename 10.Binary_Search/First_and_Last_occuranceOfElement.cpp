#include <iostream>
#include <vector>
using namespace std;
vector<int> searchRange(vector<int> &arr, int target)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    // first occurance
    int first = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] < target)
            low = mid + 1;
        else if (arr[mid] > target)
            high = mid - 1;
        else
        {
            first = mid;
            high = mid - 1;
        }
    }

    // after getting first reseting the high and low to start an new loop for getting last occurance
    low = 0;
    high = n - 1;
    // last occurance
    int last = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] < target)
            low = mid + 1;
        else if (arr[mid] > target)
            high = mid - 1;
        else
        {
            last = mid;
            low = mid + 1;
        }
    }
    return {first, last};
}
int main()
{
    vector<int> arr = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> ans = searchRange(arr, target);
    cout << ans[0] << " " << ans[1];
    return 0;
}