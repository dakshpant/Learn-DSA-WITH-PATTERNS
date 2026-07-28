#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
  unordered_map<string, int> f;
  for (int i = 0; i < wordList.size(); i++) {
    f[wordList[i]] = 1;
  }

  queue<pair<string, int>> q;

  if (f.find(beginWord) == f.end())
    f[beginWord] = 1; // if begin word not there in the list then add manually
                      // to the hashmap

  if (f.find(endWord) == f.end())
    return 0; // if end word not present then return 0

  q.push(
      {beginWord, 1}); // add the bedin word and the ladder length = 1 initially
  f.erase(beginWord);
  while (!q.empty()) {
    pair<string, int> p = q.front();
    q.pop();

    string s = p.first;
    int length = p.second;

    if (s == endWord)
      return length;

    for (int i = 0; i < s.length(); i++) {
      char c = s[i]; // iterating on each letter of teh string s
      for (int j = 97; j <= 122; j++) // small letters ascii is form [97-122]
      {
        if (c == j)
          continue; // same word appeared we ignore

        s[i] = j;

        if (f.find(s) != f.end()) {
          q.push({s, length + 1});
          f.erase(s);
        }
      }
      s[i] = c; // bacl to initial so that we can change the next letter at i =
                // 2 and so onn
    }
  }
  return 0;
}
int main() {

  string beginWord = "hit";
  string endWord = "cog";
  vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
  cout << ladderLength(beginWord, endWord, wordList);
  return 0;
}
