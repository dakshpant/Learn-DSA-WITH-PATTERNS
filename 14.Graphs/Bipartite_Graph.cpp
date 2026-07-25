#include <iostream>
#include <vector>
using namespace std;
bool res = true;
void dfsFunc(vector<vector<int>> &adj, int node, int clr, vector<int> &colors) {
  colors[node] = clr;
  for (int k = 0; k < adj[node].size(); k++) {
    int neigh = adj[node][k];
    if (colors[neigh] == -1) {
      dfsFunc(adj, neigh, 1 - clr, colors);
    } else if (colors[neigh] != -1 &&
               colors[neigh] ==
                   clr) { // means teh color of neigh is same as perent which
                          // breaks the law of bipartite
      res = false;
      return;
    }
  }
  return;
}
bool isBipartite(vector<vector<int>> &adj) {
  int n = adj.size();
  vector<int> colors(
      n, -1); // graph coloring and initially -1 denotes no color added
  // insted of colros using number 0-> red and 1 is green
  for (int i = 0; i < n; i++) {
    if (colors[i] == -1) {
      dfsFunc(adj, i, 0, colors); // for each index value if uncolored colring
                                  // it
      // starting with any color for me its 0 will change color in the func
      // using the trick
      //  0 -> 1 || 1 -> 0 => (1-clr)
    }
  }
  return res;
}
int main() {
  vector<vector<int>> adj = {
      {1, 3}, // 0
      {0, 2}, // 1
      {1, 3}, // 2
      {0, 2}  // 3
  };

  if (isBipartite(adj))
    cout << "Graph is Bipartite\n";
  else
    cout << "Graph is Not Bipartite\n";

  return 0;
}