#include <functional>
#include <iostream>
#include <vector>
using namespace std;
bool cycle = false;
void dfsFunc(vector<vector<int>> &adj, int V, int node, int parent,
             vector<bool> &vis) {
  vis[node] = true;
  for (int j = 0; j < adj[node].size(); j++) {
    int neigh = adj[node][j];
    if (vis[neigh] == true && neigh != parent) {
      cycle = true;
    }
    if (vis[neigh] == false) {
      dfsFunc(adj, V, neigh, node, vis);
    }
  }
  return;
}
bool isCycle(int V, vector<vector<int>> &edges) {
  vector<vector<int>> adj(V);
  int i;
  for (i = 0; i < edges.size(); i++) {
    int src = edges[i][0];
    int dest = edges[i][1];
    adj[src].push_back(dest);
    adj[dest].push_back(src);
  }
  vector<bool> vis(V, 0);
  int parent = -1;
  for (i = 0; i < V; i++) {
    if (vis[i] == false) {
      dfsFunc(adj, V, i, parent, vis);
    }
  }
  return cycle;
}
int main() {
  int V = 4;
  vector<vector<int>> edges = {
      {0, 1},
      {0, 2},
      {1, 2},
      {2, 3},
  };
  bool ans = isCycle(V, edges);
  cout << ans;
  return 0;
}