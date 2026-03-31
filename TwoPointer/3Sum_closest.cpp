// #include<iostream>
#include<bits/stdc++.h>
using namespace std;
int threeSumClosest(vector<int>& nums, int target){
    sort(nums.begin(), nums.end());
    int max_diff = INT_MAX;
    int best_sum = 0;
    for(int i = 0; i < nums.size() - 2; i++){
        int left = i+1;
        int right = nums.size()-1;
        while(left < right){
            int sum  = nums[i]+nums[left]+nums[right];
            int diff = abs(sum - target);
            if(diff < max_diff) {
                max_diff = diff;
                best_sum  = sum;
            }

            if(sum == target) return sum;nano ~/.bashrc
            else if(sum < target) left++;
            else right--;
        }
    }
    return best_sum;
}

int main(){
     vector<int> nums = {-1, 2, 1, -4};
    int target = 1;

  int result = threeSunClosest(nums, target)
  cout << result << endl;
    return 0;
}