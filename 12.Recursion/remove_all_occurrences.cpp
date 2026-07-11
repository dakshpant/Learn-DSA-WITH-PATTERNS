#include <iostream>
#include <string>
using namespace std;
void func(string &s, char c, int i, int n, string &res) {
  if (i == n)
    return;

  if (s[i] != c)
    res.push_back(s[i]);

  func(s, c, i + 1, n, res);
}
string removeAllOccurrences(string &s, char c) {
  int n = s.size();
  string res = "";
  func(s, c, 0, n, res);
  return res;
}
int main() {
  string s = "babbar";
  char c = 'b';
  cout << removeAllOccurrences(s, c);
  return 0;
}