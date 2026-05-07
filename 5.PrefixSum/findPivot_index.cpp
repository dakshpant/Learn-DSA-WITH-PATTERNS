#include<iostream>
#include<vecotr>
#include<climit>
using namespace std;
int pivitIndex(vector<int>&nums){
   int left = 0;
   int sum = 0;
   for(int i = 0; i<nums.size();i++){
    sum += nums[i];
   } 
   for(int i = 0; i < nums.size(); i++){
    int right = sum - nums[i]- left;
    if(right == left) return i;
    left += nums[i];
   }
   return -1;
}
int main(){
    vector<int>nums = {1,7,3,6,5,6};
    cout<<pivitIndex(nums)<<endl;
    return 0;
}