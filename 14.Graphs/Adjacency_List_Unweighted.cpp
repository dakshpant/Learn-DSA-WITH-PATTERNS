#include <initializer_list>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
vector<vector<int>> adjList(int n, vector<pair<int, int>> edges) {
  vector<vector<int>> adj(n);
  for (int i = 0; i < edges.size(); i++) {
    pair<int, int> edge = edges[i];
    int src = edge.first;
    int dest = edge.second;

    adj[src].push_back(dest);
    // if undirected graph if not remove
    adj[dest].push_back(src);
  }
  return adj;
}
int main() {
  int n = 5;
  vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 4}};
  vector<vector<int>> ans = adjList(n, edges);
  for (int i = 0; i < ans.size(); i++) {
    cout << i << " -- > ";
    for (int j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}