#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
void func(string &digits, unordered_map<char, string> &f, int n, int idx,
          string &diary, vector<string> &res) {
  if (idx == n) {
    res.push_back(diary);
    return;
  }

  string choices = f[digits[idx]];
  for (auto i : choices) {
    diary.push_back(i);
    func(digits, f, n, idx + 1, diary, res);
    diary.pop_back();
  }
  return;
}
vector<string> letterCombinations(string digits) {
  unordered_map<char, string> f;
  f['1'] = "";
  f['2'] = "abc";
  f['3'] = "def";
  f['4'] = "ghi";
  f['5'] = "jkl";
  f['6'] = "mno";
  f['7'] = "pqrs";
  f['8'] = "tuv";
  f['9'] = "wxyz";
  f['0'] = " ";
  int idx = 0;
  int n = digits.size();
  string diary = "";
  vector<string> res;

  func(digits, f, n, idx, diary, res);
  return res;
}
int main() {
  string digits = "2";
  vector<string> ans = letterCombinations(digits);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  return 0;
}