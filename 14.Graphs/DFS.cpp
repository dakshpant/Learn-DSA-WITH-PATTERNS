#include <iostream>
#include <vector>
using namespace std;
void func(vector<vector<int>> &adj, int node, vector<int> &res,
          vector<bool> &visited) {
  res.push_back(node);
  visited[node] = true;

  for (int i = 0; i < adj[node].size(); i++) {
    int neighbout = adj[node][i]; // iterating on the inside valures of each
                                  // node which are the neighbours of that node

    if (visited[neighbout] == false) {
      func(adj, neighbout, res, visited);
    }
  }
  return;
}
vector<int> dfs(vector<vector<int>> &adj) {
  int n = adj.size();
  vector<int> res;
  vector<bool> visited(n, 0); // defined teh size of the visited arr as the nno.
                              // of nodes and setting them all initially 0

  func(adj, 0, res, visited);
  return res;
}
int main() {
  vector<vector<int>> adj = {
      {2, 3, 1}, {0}, {0, 4}, {0}, {2},
  };
  vector<int> ans = dfs(adj);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}