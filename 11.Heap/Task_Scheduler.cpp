#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
int LeastInterval(vector<char> &tasks, int gap) {
  int n = tasks.size();
  unordered_map<char, int> f;
  unordered_map<char, int> free;
  for (int i = 0; i < n; i++) {
    f[tasks[i]]++;
    free[tasks[i]] = 1;
  }
  priority_queue<pair<int, char>> pq;
  int seat = 1;

  for (auto i : f)
    pq.push({i.second, i.first});

  while (!pq.empty()) {
    vector<pair<int, char>> taskPulled;
    while (!pq.empty()) {
      pair<int, char> t = pq.top();
      pq.pop();
      if (free[t.second] <= seat) {
        if (t.first > 1)
          pq.push({t.first - 1, t.second});
        free[t.second] = seat + gap + 1;
        break;
      } else {
        taskPulled.push_back(t);
      }
    }
    for (auto i : taskPulled)
      pq.push(i);
    seat++;
  }
  return seat - 1;
}
int main() {
  vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
  int gap = 2;
  cout << LeastInterval(tasks, gap);
  return 0;
}