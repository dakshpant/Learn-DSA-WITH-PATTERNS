#include <iostream>
#include <queue>
#include <vector>
using namespace std;
bool isVisited(int i, int j, int n, int m) {
  if (i < 0 || i >= n || j < 0 || j >= m)
    return false;
  return true;
}
int orangesRotting(vector<vector<int>> &grid) {
  int n = grid.size();
  int m = grid[0].size();
  int time = 0;
  int fresh = 0;
  int i, j;
  int x[4] = {-1, 1, 0, 0};
  int y[4] = {0, 0, -1, 1};
  queue<pair<int, int>> q;
  // triversing the whole grid and adding all the rotten oranges to the queue
  // and counting the number of fresh oranges
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (grid[i][j] == 2) {
        q.push({i, j});
        grid[i][j] = -2;
      } else if (grid[i][j] == 1) {
        fresh++;
      }
    }
  }
  while (!q.empty() && fresh > 0) {
    time++;
    int s = q.size();
    while (s--) {
      pair<int, int> frnt = q.front();
      q.pop();
      int r = frnt.first;
      int c = frnt.second;
      for (int k = 0; k < 4; k++) {
        int row = r + x[k];
        int col = c + y[k];
        if (isVisited(row, col, n, m) && grid[row][col] == 1) {
          q.push({row, col});
          grid[row][col] = -1;
          fresh--;
        }
      }
    }
  }
  if (fresh > 0)
    return -1; // Return the minimum number of minutes that must elapse until no
  // cell has a fresh orange. If this is impossible, return -1. in ques given
  return time;
}

int main() {
  vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};

  cout << "Minimum time required to rot all the oranges: "
       << orangesRotting(grid) << endl;
  return 0;
}