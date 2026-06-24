#include<iostream>
#include<vector>
using namespace std;
int search(vector<int> &nums, int target){
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    while(low <= high){
     int guess = (low + high) / 2;
     if(nums[guess] == target) return guess;
     
     if(nums[guess] > nums[n - 1])//basically in a rotated sorted array [40,50,60,0,10,20] we check if guess comes out to be 40 so => 40 > 20 means its in part 1 hen the inner logic wil work else continue to part 2 logic
     {
        if(nums[guess] < target) low  = guess + 1;
        else{
            if(nums[0] > target) low = guess + 1;
            else high = guess - 1;
        }
     }

     //means the in the arr[40,50,60,0,10,20] if guess is 10 so 10  < 20 hence this will work
     else{
        if(nums[guess] > target)//guessed 20 and target is 10 
        high = guess - 1;
        else{
            if(nums[n-1] < target) high = guess - 1;
            else low = guess + 1;
        }
     }
    }
    return -1;
}
int main(){
    int target = 10;
    vector<int> nums = {5,6,7,8,9,10,0,1,2,3,4};
    int ans = search(nums, target);
    cout<< ans<<endl;
    return 0;   
}