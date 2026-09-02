#include <iostream>
#include <vector>
using namespace std;
int func(string &s, int idx, vector<int> &dp) {
  if (idx == s.size())
    return 1;
  if (dp[idx] != -1)
    return dp[idx];
  int c1 = 0;
  int c2 = 0;
  if (s[idx] != '0')
    c1 = func(s, idx + 1, dp);
  if (idx + 1 < s.size()) {
    if (s[idx] == '1' || (s[idx] == '2' && s[idx + 1] <= '6')) {
      c2 = func(s, idx + 2, dp);
    }
  }
  return dp[idx] = c1 + c2;
}
int decode(string s) {
  vector<int> dp(s.size(), -1);
  int idx = 0;
  return func(s, idx, dp);
}
int main() {
  string s = "122";
  cout << decode(s) << endl;
  return 0;
}