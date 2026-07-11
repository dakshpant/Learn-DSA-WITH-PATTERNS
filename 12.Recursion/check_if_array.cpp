#include <iostream>
#include <vector>
using namespace std;
bool func(int idx, int n, vector<int> &a) {
  if (idx == n || idx == n - 1)
    return true;

  if (a[idx] >= a[idx + 1])
    return false;
  return func(idx + 1, n, a);
}
bool isArraySorted(vector<int> &a) {
  int n = a.size();

  bool ans = func(0, n, a);
  return ans;
}
int main() {
  vector<int> a = {10, 60, 30, 40, 50};
  cout << isArraySorted(a);
  return 0;
}