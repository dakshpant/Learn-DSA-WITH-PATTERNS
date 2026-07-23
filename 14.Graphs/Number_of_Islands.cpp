#include <iostream>
#include <vector>
using namespace std;
vector<int> x = {-1, 1, 0, 0};
vector<int> y = {0, 0, -1, 1};

bool isValid(int i, int j, int n, int m) {
  if (i < 0 || j < 0 || i >= n || j >= m)
    return false;
  return true;
}

void dfsFunc(int n, int m, int i, int j, vector<vector<char>> &grid,
             vector<vector<bool>> &visited) {
  visited[i][j] = true;
  for (int k = 0; k < 4; k++) {
    int row = i + x[k];
    int col = j + y[k];
    if (isValid(row, col, n, m) && grid[row][col] == '1' &&
        visited[row][col] == false) {
      dfsFunc(n, m, row, col, grid, visited);
    }
  }
  return;
}
int numIslands(vector<vector<char>> &grid) {
  int n = grid.size();
  int m = grid[0].size();
  int i, j;
  int res = 0;
  vector<vector<bool>> visited(n, vector<bool>(m, false));

  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (grid[i][j] == '1' && visited[i][j] == false) {
        dfsFunc(n, m, i, j, grid, visited);
        res++;
      }
    }
  }
  return res;
}
int main() {
  vector<vector<char>> grid = {{'1', '1', '1', '1', '0'},
                               {'1', '1', '0', '0', '0'},
                               {'1', '1', '0', '1', '0'},
                               {'0', '0', '0', '0', '1'}};//3
  cout << "Number of Islands: " << numIslands(grid) << endl;
  return 0;
}