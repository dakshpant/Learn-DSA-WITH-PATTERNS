#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int shortedpath(vector<vector<int>> &edges, int n, int src, int dest) {
  vector<vector<int>> adj(n);
  for (int i = 0; i < edges.size(); i++) {
    int s = edges[i][0];
    int t = edges[i][1];
    adj[s].push_back(t);
    adj[t].push_back(s);
  }
  vector<int> vis(n, 0);
  vector<int> res(n, -1); // why -1? if any dest not visited and if asked ans
                          // for will return -1
  queue<pair<int, int>> q;
  q.push({src, 0});
  vis[src] = 1;

  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();
    int node = p.first;
    int dist = p.second;
    res[node] = dist;
    for (int i = 0; i < adj[node].size(); i++) {
      int neigh = adj[node][i];
      if (vis[neigh] == 0) {
        q.push({neigh, dist + 1});
        vis[neigh] = 1;
      }
    }
  }
  return res[dest];
}
int main() {
  int n = 7;
  int dest = 6;
  vector<vector<int>> edges = {
      {0, 1}, {1, 2}, {1, 3}, {2, 4}, {3, 4}, {3, 5}, {4, 6}, {5, 6},
  };
  cout << "Shortest path from " << 0 << " to " << dest << " is "
       << shortedpath(edges, n, 0, dest) << endl;
  return 0;
}