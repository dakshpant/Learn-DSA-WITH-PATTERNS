#include <iostream>
#include <unordered_map>
using namespace std;
bool isValid(string s, string t){
    if(s.size() != t.size()) return false;
unordered_map<char, int> fs;
unordered_map<char, int> ft;
    for(int i = 0; i < s.size();i++){
        fs[s[i]]++;
        ft[t[i]]++;
    }
    return fs == ft;
}
int main() {
  string s = "anagram";
  string t = "nagaram";
  cout << isValid(s, t);
  return 0;
}