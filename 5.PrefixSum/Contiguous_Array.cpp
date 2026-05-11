#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;
int findMaxLength(vector<int> &nums)
{
    int ans = 0;
    int sum = 0;
    int one = 0;
    int zero = 0;
    unordered_map<int, int> f;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
            zero++;
        else
            one++;
        int diff = zero - one;
        if (diff == 0)
        {
            ans = max(ans, i + 1);
        }
        else if (f.find(diff) == f.end())
            f[diff] = i; // first time seeing this difference
        else
        {
            int idx = f[diff]; // laal part ki length hae
            int len = i - idx; // ye total length - laal = green k length
            /*
            the smaller the idxthe larger the len hence teh larger the contegious subarray length
            */
            ans = max(len, ans);
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {0, 1, 1, 1, 1, 1, 0, 0, 0};
    int ans = findMaxLength(nums);
    cout << ans << endl;
    return 0;
}