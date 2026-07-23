#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> bfs(vector<vector<int>> &adj) {
  int n = adj.size();
  vector<int> res;
  vector<bool> visited(n, 0);
  queue<int> q;
  q.push(0);
  visited[0] = true;

  while (!q.empty()) {
    int node = q.front();
    q.pop();
    res.push_back(node);
    for (int i = 0; i < adj[node].size(); i++) {
      int neighbour = adj[node][i];
      if (visited[neighbour] == false) {
        q.push(neighbour);
        visited[neighbour] = true;
      }
    }
  }
  return res;
}

int main() {
  vector<vector<int>> adj = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};

  vector<int> ans = bfs(adj);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i];
  }
  return 0;
}