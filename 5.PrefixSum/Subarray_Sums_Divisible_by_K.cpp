#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int subarraysDivByK(vector<int>& nums, int k) {
    int sum = 0;
    int ans = 0;
    unordered_map<int, int> mpp;
    mpp[0] = 1;
    for(int i = 0; i < nums.size(); i++){
        sum += nums[i];
        int rem = sum % k;
        if(rem < 0) rem+=k;
        ans += mpp[rem];
        mpp[rem]++;
    }
    return ans;
}
int main(){
    vector<int> nums = {4,5,0,-2,-3,1};
    int k = 5;
    int ans = subarraysDivByK(nums,k);
    cout<<ans<<endl;
    return 0;
}