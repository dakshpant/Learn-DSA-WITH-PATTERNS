#include <iostream>
#include <ratio>
#include <vector>
using namespace std;
bool cycle = false;
void dfsFunc(vector<vector<int>> &adj, int V, int node, vector<bool> &path,
             vector<bool> &vis) {
  vis[node] = true;
  path[node] = true;
  for (int k = 0; k < adj[node].size(); k++) {
    int neigh = adj[node][k];
    if (vis[neigh] == true && path[neigh] == true)
      cycle = true;
    if (vis[neigh] == false)
      dfsFunc(adj, V, neigh, path, vis);
  }
  path[node] = false;
  return;
}
bool isCycle(int V, vector<vector<int>> &edges) {
  int i;
  vector<vector<int>> adj(V);
  for (i = 0; i < edges.size(); i++) {
    int src = edges[i][0];
    int dest = edges[i][1];
    adj[src].push_back(dest);
  }
  vector<bool> vis(V, 0);
  vector<bool> path(V, 0);
  for (i = 0; i < V; i++) {
    if (vis[i] == false) {
      dfsFunc(adj, V, i, path, vis);
    }
  }
  return cycle;
}
int main() {
  int V = 4;
  vector<vector<int>> adj = {{0, 1}, {1, 2}, {2, 0}, {2, 3}};
  bool ans = isCycle(V, adj);
  cout << ans;
  return 0;
}