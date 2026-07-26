#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int networkDelayTime(vector<vector<int>> &times, int n, int k) {
  vector<vector<pair<int, int>>> adj(n);
  for (int i = 0; i < times.size(); i++) {
    int src = times[i][0];
    int dest = times[i][1];
    int wt = times[i][2];
    adj[src - 1].push_back(
        {dest - 1, wt}); // since in question nodes are 1 to n
                         // but in code we start from 0 for ease of coding
  }
  vector<int> time(n, INT_MAX);
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  pq.push({0, k - 1});
  time[k - 1] = 0;

  while (!pq.empty()) {
    pair<int, int> p = pq.top();
    pq.pop();

    int t = p.first;
    int node = p.second;

    if (t > time[node])
      continue;

    for (int i = 0; i < adj[node].size(); i++) {
      int neigh = adj[node][i].first;
      int wt = adj[node][i].second;
      if (time[neigh] > t + wt) {
        time[neigh] = t + wt;
        pq.push({t + wt, neigh});
      }
    }
  }

  int maxTime = 0;

  for (int i = 0; i < n; i++) {

    if (time[i] == INT_MAX)
      return -1;

    maxTime = max(maxTime, time[i]);
  }

  return maxTime;
}
int main() {
  vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
  int n = 4;
  int k = 2;
  cout << networkDelayTime(times, n, k) << endl;
  return 0;
}