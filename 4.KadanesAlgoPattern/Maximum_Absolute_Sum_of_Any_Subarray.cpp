#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int maxAbsoluteSum(vector<int>& nums) {
    int maxSum = nums[0];
    int maxEnding = nums[0];
    int minSum = nums[0];
    int minEnding = nums[0];
    for(int i = 1; i<nums.size();i++){
        maxEnding = max(nums[i], maxEnding+nums[i]);
        maxSum = max(maxSum,maxEnding);
        minEnding = min(nums[i], minEnding+nums[i]);
        minSum = min(minSum,minEnding);
    }
    return max(abs(minSum), abs(maxSum));
}
int main(){
    vector<int> nums = {1,-3,2,3,-4};
    int ans = maxAbsoluteSum(nums);
    cout<<ans<<endl;
    return 0;
}