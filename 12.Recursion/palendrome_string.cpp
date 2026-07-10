#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool func(string &s, int low, int high) {
  int len = (high - low) + 1;
  if (len == 0 || len == 1)
    return true;

  if (s[low] != s[high])
    return false;

  return func(s, low + 1, high - 1);
}

bool isPalindrome(string &s) {
  int low = 0;
  int high = s.size() - 1;
  return func(s, low, high);
}
int main() {
  string s = "malayalam";
  bool ans = isPalindrome(s);
  if (ans == 1)
    cout << "True";
  else
    cout << "False";
  return 0;
}
