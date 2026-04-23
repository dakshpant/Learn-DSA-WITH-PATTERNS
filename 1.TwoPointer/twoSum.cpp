// https://leetcode.com/problems/two-sum/description/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // sorted, array, return 2 indices =>2 pointer will be used
        // return the indices=>ans[i] and ans[j]=>i and j are the pointers
        // since unsorte array use hashmap

        // with HashMap
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            int difference = target - nums[i];
            if (mpp.find(difference) != mpp.end()) {
                return {mpp[difference], i};
            }
            mpp[nums[i]] = i;
        }
        return {-1,-1};
        // Without Hashmap
        // int i = 0;
        // int j = nums.size() - 1;
        // sort(nums.begin(), nums.end());
        // while (i < j) {
        //     int sum = nums[i] + nums[j];
        //     if (sum == target) {
        //         return {i, j};
        //     } else if (sum < target)
        //         i++;
        //     else if (sum > target)
        //         j--;
        // }
        // return {-1, -1};
    }
};
int main(){
    Solution obj;

    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> ans = obj.twoSum(nums, target);
    cout << ans[0] << " " << ans[1];

    return 0;
}