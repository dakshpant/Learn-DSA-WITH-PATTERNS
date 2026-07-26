#include <algorithm>
#include <climits>
#include <initializer_list>
#include <iostream>
#include <mutex>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
bool isValid(int i, int j, int n, int m) {
  if (i < 0 || j < 0 || i >= n || j >= m)
    return false;
  return true;
}
int minimumEffortPath(vector<vector<int>> &heights) {
  int n = heights.size();
  int m = heights[0].size();
  vector<vector<int>> efforts(n, vector<int>(m, INT_MAX));
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                 greater<pair<int, pair<int, int>>>>
      pq;

  efforts[0][0] = 0;
  pq.push({0, {0, 0}});
  int x[4] = {-1, 1, 0, 0};
  int y[4] = {0, 0, -1, 1};
  while (!pq.empty()) {
    pair<int, pair<int, int>> p = pq.top();
    pq.pop();
    int currEff = p.first;
    int currR = p.second.first;
    int currC = p.second.second;
    if (currEff > efforts[currR][currC])
      continue;
    for (int i = 0; i < 4; i++) {
      int nextR = currR + x[i];
      int nextC = currC + y[i];
      if (!isValid(nextR, nextC, n, m))
        continue;

      int absDiff_height = abs(heights[currR][currC] - heights[nextR][nextC]);
      int nextEff = max(currEff, absDiff_height);
      if (nextEff < efforts[nextR][nextC]) {
        efforts[nextR][nextC] = nextEff;
        pq.push({nextEff, {nextR, nextC}});
      }
    }
  }
  return efforts[n - 1][m - 1];
}

int main() {
  vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
  cout << minimumEffortPath(heights);
  return 0;
}