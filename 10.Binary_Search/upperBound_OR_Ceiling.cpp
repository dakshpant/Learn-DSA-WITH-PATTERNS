#include <iostream>
#include <vector>
using namespace std;
int CB(vector<int> &arr, int target)
{

    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int res = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= target)
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}

int main()
{
    vector<int> arr = {1, 2, 8, 10, 11, 12, 19};
    int target = 5;
    int ans = CB(arr, target);
    cout<<ans<<endl;
    return 0;
}