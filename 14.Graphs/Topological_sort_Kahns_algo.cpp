#include <cstddef>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> topoSort(int n, vector<vector<int>> &edges) {
  vector<vector<int>> adj(n);
  vector<int> inDegree(n, 0);
  vector<int> res;
  for (int i = 0; i < edges.size(); i++) {
    int src = edges[i][0];
    int dest = edges[i][1];
    adj[src].push_back(dest);
    inDegree[dest]++;
  }
  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (inDegree[i] == 0)
      q.push(i);
  }
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    res.push_back(node);
    for (int i = 0; i < adj[node].size(); i++) {
      int neigh = adj[node][i];
      inDegree[neigh]--;
      if (inDegree[neigh] == 0)
        q.push(neigh);
    }
  }
  return res;
}
int main() {
  int n = 4;
  vector<vector<int>> edges = {
      {3, 0},
      {1, 0},
      {2, 0},
  };
  vector<int> ans = topoSort(n, edges);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  return 0;
}