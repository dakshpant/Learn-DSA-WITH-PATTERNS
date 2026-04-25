#include<iostream>
using namespace std;
int findDuplicate(vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0];
    while(true){
        slow = nums[slow];
        fast = nums[nums[fast]];
        if(fast == slow){
            slow = nums[0];
            while (slow != fast){
                slow = nums[slow];
                fast = nums[fast];
            }
            return slow;
        }
    }
    return -1;
}
int main(){
    vector<int> nums = {1,3,4,2,2};
    int ans = findDuplicate(nums);
    cout<<ans<< endl;
    return 0;
}