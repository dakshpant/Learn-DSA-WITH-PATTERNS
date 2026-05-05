#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int sumCircularArray(vector<int>& nums){
    int maxEnding =  nums[0];
    int maxSum = nums[0];

    int minSum = nums[0];
    int minEnding = nums[0];

    int totalSum = nums[0];

    for(int i =1; i < nums.size(); i++){
        maxEnding = max(maxEnding + nums[i], nums[i]);
        maxSum = max(maxSum, maxEnding);

        minEnding = min(nums[i],minEnding + nums[i]);
        minSum = min(minSum, minEnding);
    }
    return ((maxSum < 0) ? maxSum: max(maxSum, totalSum - minSum)); 
}
int main(){
    vector<int> nums = {1,-2,3,-2};
    int ans = sumCircularArray(nums);
    cout<< ans << endl;
    return 0;
}