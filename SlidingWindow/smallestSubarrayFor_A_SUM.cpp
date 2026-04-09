#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int minSubarraySize(int target ,vector<int>& nums){
int low = 0;
int high = 0;
int sum = 0;
int minSize = INT_MAX;
while(high < nums.size()){
    //Checks the sum of current subarray/window
    sum += nums[high];
    while (sum >= target)
    {
        //to get the size of current window
        int currSize = high - low + 1; //std formula to get the array size
        minSize = min(minSize, currSize);
        //to fire teh first hired employee {1,2,3,4}=>update the sum by removing the first value from the sum and then moving the window fwd
        sum -= nums[low];
        low ++;//shrinks the window
    }
    high ++;//expands the window
}
return (minSize == INT_MAX ? 0 : minSize);
}
int main(){
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    int ans = minSubarraySize(target, nums);
    cout<< ans << endl;
    return 0;
}