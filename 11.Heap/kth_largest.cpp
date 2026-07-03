#include <iostream>
#include <vector>
#include <functional>
using namespace std;

int kthLargest(vector<int> &nums, int k){
    int n = nums.size();
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int i = 0;  i < k; i++) minHeap.push(nums[i]);

    for(int i = k; i < n; i++){
        if(nums[i] <= minHeap.top()) continue;

        minHeap.pop();
        minHeap.push(nums[i]);
    }
    return minHeap.top();
}

int main(){
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    int ans = kthLargest(nums,k);
    cout<<ans<<endl;
    return 0;
}