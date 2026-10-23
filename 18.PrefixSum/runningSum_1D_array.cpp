#include <iostream>
#include <vector>
using namespace std;
vector<int> runningSum(vector<int> &nums)
{
    int n = nums.size();
    vector<int> pre(n);
    pre[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + nums[i];
    }
    return pre;
}
int main()
{
    vector<int> nums = {3, 1, 2, 10, 1};

    vector<int> ans = runningSum(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}