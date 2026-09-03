#include <vector>
#include <iostream>
using namespace std;
int minOperations(vector<int> &nums) {
  int n = nums.size();
  int count = 0;
  for (int i = 0; i < n - 1; i++) {
    if (nums[i] >= nums[i + 1]) {
      int diff = nums[i] - nums[i + 1];
      count += diff + 1;
      nums[i + 1] += diff + 1;
    }
  }
  return count;
}
int main() {
  vector<int> nums = {1, 1, 1};
cout << minOperations(nums);
  return 0;
}
