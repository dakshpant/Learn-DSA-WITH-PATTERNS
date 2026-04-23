#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
//Method 1
int maxSubarraySum(vector<int>& nums, int k){
/*
=======Approach======
low = 0
high = k-1
int maxSum = int_max

safety check=> if(arr.size < k) break
int prevSum = 0;
for(int i = low; i<high;i++){
sum+=arr[i];//total sum of each window
}
maxSum = prevSum;
while(high < arr.size){
maxSum = max(maxSum, prevSum);
low++;//to move the window
high++;

prevSum -= arr[low-1];//to move the window we remove the previous whidows lowest
prevSum += arr[high]
}
*/

int low = 0;
int high = k -1;
int maxSum = INT_MIN;
int sum = 0;
for(int i = low; i <= high; i++){
    sum += nums[i];
}
maxSum = sum;
while(high < nums.size()){
    maxSum = max(maxSum, sum);
    low++;
    high++;

    sum -= nums[low - 1];
    sum += nums[high];
}
return maxSum;
}

//Method 2
// int maxSubarraySum(vector<int>& nums, int k){
//     int sum = 0;

//     for(int i = 0; i < k; i++)
//         sum += nums[i];

//     int maxSum = sum;

//     for(int i = k; i < nums.size(); i++){
//         sum += nums[i] - nums[i-k];// based on windowSum = prevSum + arr[high] - arr[Low-1]
//         maxSum = max(maxSum, sum);
//     }

//     return maxSum;
// }
int main(){
    vector<int> nums = {100, 200, 300, 400};
    int k = 2;
   int ans = maxSubarraySum(nums, k);
    cout<< ans << endl;
    return 0;
}