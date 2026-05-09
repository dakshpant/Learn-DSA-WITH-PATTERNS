#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int subarraySum(vector<int> &nums, int k){
int sum = 0;
int res = 0;
unordered_map<int, int> mpp;
mpp[0] = 1;
for(int i =0; i < nums.size(); i++){
    sum += nums[i];
    int ques = sum - k;
    int freq = mpp[ques];
    res  += freq;
    mpp[sum]++;
}
return res;
}
int main(){
    vector<int> nums = {1,2,3};
    int k = 3;
    int ans = subarraySum(nums,k);
    cout<<ans<<endl;
    return 0;
}