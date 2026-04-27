#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int maxSubarraySum(vector<int>& nums){
int bestEnding = nums[0];
int ans = nums[0];
//i = 1 not 0 cuz 0 already included above 
for(int i = 1; i<nums.size(); i++){
    int v1 = bestEnding + nums[i];
    int v2 = nums[i];
    bestEnding = max(v1, v2);
    ans = max(bestEnding,ans);
}
return ans;
}
int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int ans = maxSubarraySum(nums);
    cout<<ans;
return 0;
}