#include<iostream>
#include<unordered_map>
#include<climits>
#include<vector>
using namespace std;
int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int res = INT_MIN;
        int h = 0;
        int zeros = 0;
        for(h = 0; h < nums.size();h++){
            if(nums[h]==0) zeros++;
            while(zeros>k){
                if(nums[l]==0) zeros--;
                l++;
            }
        int len = h-l+1;
        res = max(res,len);
        }
        return res;
    }
int main(){
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    int ans = longestOnes(nums,k);
    cout<<ans<<endl;
    return 0;
}