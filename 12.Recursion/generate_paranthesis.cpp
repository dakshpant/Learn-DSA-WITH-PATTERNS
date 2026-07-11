#include <iostream>
#include <string>
#include <vector>
using namespace std;
void func(int open, int close, int n, vector<string> &res, string &tmp) {
  // base case - when we have added all the open and close brackets and
  if (open == n && close == n) {
    res.push_back(tmp);
    return;
  }

  if (open < n) { // condition - if open bracket is less than n then we can
                  // add open bracket
    tmp.push_back('(');
    func(open + 1, close, n, res, tmp);
    tmp.pop_back(); // after a universe if visited we Backtrack to the parent
                    // case to try the other possibilities
                    // so pop is needed to backteack
  }
  if (close < open) { // condition since open and close can't be equal and
                      // without open clsoe cant exits
    tmp.push_back(')');
    func(open, close + 1, n, res, tmp);
    tmp.pop_back();
  }

  return;
}
vector<string> generateParenthesis(int n) {
  string tmp = "";
  vector<string> res;
  func(0, 0, n, res, tmp);
  return res;
}
int main() {
  int n = 4;
  vector<string> ans = generateParenthesis(n);
  for (auto s : ans) {
    cout << s << endl;
  }
  return 0;
}