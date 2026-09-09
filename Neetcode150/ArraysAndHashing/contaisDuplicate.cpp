#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
bool containsDuplicate(vector<int> &nums) {
  int n = nums.size();
  unordered_set<int> f;
  for (int num : nums) {
    if (f.count(num))
      return true;
    f.insert(num);
  }
  return false;
}
int main() {
  vector<int> nums = {1, 2, 3, 1};
  cout << containsDuplicate(nums);
}