#include <iostream>
#include <vector>
using namespace std;
vector<int> bellman(int n, vector<vector<int>> &edges, int src) {
  vector<int> res(n, 1e8);
  res[src] = 0;

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < edges.size(); j++) {
      int s = edges[j][0];
      int d = edges[j][1];
      int wt = edges[j][2];

      if (res[s] != 1e8 && res[d] > res[s] + wt) {
        res[d] = res[s] + wt;
      }
    }
  }
  // Negative cycle detection
  for (int k = 0; k < edges.size(); k++) {
    int s = edges[k][0];
    int d = edges[k][1];
    int wt = edges[k][2];

    if (res[s] != 1e8 && res[d] > res[s] + wt) {
      return {-1};
    }
  }
  return res;
}
int main() {
  int n = 5;
  int src = 0;
  vector<vector<int>> edges = {
      {1, 3, 2}, {4, 3, -1}, {2, 4, 1}, {1, 2, 1}, {0, 1, 5}};
  vector<int> res = bellman(n, edges, src);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}