#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
vector<int> dijkstra(int n, vector<vector<int>> &edges, int src) {
  vector<vector<pair<int, int>>> adj(n);
  for (int i = 0; i < edges.size(); i++) {
    int s = edges[i][0];
    int d = edges[i][1];
    int wt = edges[i][2];

    adj[s].push_back({d, wt});
    adj[d].push_back({s, wt});
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  vector<int> dist(n, INT_MAX);

  pq.push({0, src});
  dist[src] = 0;

  while (!pq.empty()) {
    pair<int, int> p = pq.top();
    pq.pop();
    int d = p.first;
    int node = p.second;

    if (d > dist[node])
      continue;

    for (int k = 0; k < adj[node].size(); k++) {
      int neigh = adj[node][k].first;
      int wt = adj[node][k].second;
      if (dist[neigh] > d + wt) {
        dist[neigh] = d + wt;
        pq.push({d + wt, neigh});
      }
    }
  }
  return dist;
}
int main() {
  int n = 5;
  int src = 0;
  vector<vector<int>> edges = {{0, 1, 9}, {0, 4, 3}, {1, 2, 5},
                               {1, 3, 7}, {2, 3, 4}, {3, 4, 6}};
  vector<int> res = dijkstra(n, edges, src);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}