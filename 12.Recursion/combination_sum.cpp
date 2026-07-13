#include <iostream>
#include <vector>
using namespace std;
void func(int n, int idx, int sum, int target, vector<int> &arr,
          vector<int> &diary, vector<vector<int>> &res) {
  // base case
  if (idx == n) {
    if (sum == target)
      res.push_back(diary);
    return;
  }

  // recursive case
  // choice 1 = skip idx and move to next
  func(n, idx + 1, sum, target, arr, diary, res);
  if (arr[idx] + sum <= target) {
    // choice 2 = take idx and move to next
    diary.push_back(arr[idx]);
    sum += arr[idx];
    func(n, idx, sum, target, arr, diary, res);
    diary.pop_back();
    sum -= arr[idx];
  }
  return;
}
vector<vector<int>> combinationSum(vector<int> &arr, int target) {
  int n = arr.size();
  int idx = 0;
  int sum = 0;
  vector<int> diary;
  vector<vector<int>> res;

  func(n, idx, sum, target, arr, diary, res);
  return res;
}
int main() {
  vector<int> arr = {2, 3, 6, 7};
  int target = 7;
  vector<vector<int>> ans = combinationSum(arr, target);
  for (auto it : ans) {
    for (auto i : it) {
      cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}