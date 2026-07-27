#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int prims(vector<vector<int>> &edges, int n) {
  vector<vector<pair<int, int>>> adj(n);
  for (int i = 0; i < edges.size(); i++) {
    int src = edges[i][0];
    int dest = edges[i][1];
    int w = edges[i][2];
    adj[src].push_back({dest, w});
    adj[dest].push_back({src, w});
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  vector<int> visited(n, 0);

  int sum = 0;
  pq.push({0, 0});

  while (!pq.empty()) {
    pair<int, int> p = pq.top();
    pq.pop();

    int w = p.first;
    int node = p.second;

    if (visited[node] == 1)
      continue;

    visited[node] = 1;
    sum += w;
    for (int i = 0; i < adj[node].size(); i++) {
      int neigh = adj[node][i].first;
      int neighWt = adj[node][i].second;

      if (visited[neigh] == 1)
        continue;

      pq.push({neighWt, neigh});
    }
}
return sum;
}
int main() {
  int n = 5;
  vector<vector<int>> edges = {
      {0, 1, 10}, {0, 2, 6}, {0, 3, 1}, {1, 3, 2}, {2, 3, 4},
  };

  cout << prims(edges, n) << endl;
  return 0;
}