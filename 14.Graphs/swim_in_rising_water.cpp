#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
bool isValid(int i, int j, int n, int m) {
  if (i < 0 || j < 0 || i >= n || j >= m)
    return false;
  return true;
}
int swimInWater(vector<vector<int>> &grid) {
  int n = grid.size();
  int m = grid[0].size();

  vector<vector<int>> waterLevel(n, vector<int>(m, 1e8));
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                 greater<pair<int, pair<int, int>>>>
      pq;

  waterLevel[0][0] = grid[0][0];
  pq.push({grid[0][0], {0, 0}});

  int x[4] = {-1, 1, 0, 0};
  int y[4] = {0, 0, -1, 1};

  while (!pq.empty()) {
    pair<int, pair<int, int>> p = pq.top();
    pq.pop();

    int currLevel = p.first;
    int cr = p.second.first;
    int cc = p.second.second;
    if (currLevel > waterLevel[cr][cc])
      continue;

    for (int i = 0; i < 4; i++) {
      int nr = cr + x[i];
      int nc = cc + y[i];

      if (!isValid(nr, nc, n, m))
        continue;

      int newLevel = max(currLevel, grid[nr][nc]);
      if (newLevel < waterLevel[nr][nc]) {
        waterLevel[nr][nc] = newLevel;
        pq.push({newLevel, {nr, nc}});
      }
    }
  }
  return waterLevel[n - 1][m - 1];
}
int main() {
  vector<vector<int>> grid = {{0, 2}, {1, 3}};

  cout << swimInWater(grid) << endl;

  return 0;
}