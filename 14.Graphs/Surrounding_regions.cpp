#include <iostream>
#include <vector>
using namespace std;
int x[4] = {-1, 1, 0, 0};
int y[4] = {0, 0, -1, 1};
bool isValid(int i, int j, int n, int m) {
  if (i < 0 || j < 0 || i >= n || j >= m)
    return false;
  return true;
}
void dfsFunc(vector<vector<char>> &board, int i, int j, int n, int m) {
  board[i][j] = '#';
  for (int k = 0; k < 4; k++) {
    int row = i + x[k];
    int col = j + y[k];
    if (isValid(row, col, n, m) && board[row][col] == 'O') {
      dfsFunc(board, row, col, n, m);
    }
  }
  return;
}
void solve(vector<vector<char>> &board) {
  int n = board.size();
  int m = board[0].size();
  int i, j;

  // first row
  for (int i = 0; i < n; i++) {
    if (board[i][0] == 'O') {
      dfsFunc(board, i, 0, n, m);
    }
  }
  // last row
  for (i = 0; i < n; i++) {
    if (board[i][m - 1] == 'O')
      dfsFunc(board, i, m - 1, n, m);
  }
  // first column
  for (i = 0; i < m; i++) {
    if (board[0][i] == 'O')
      dfsFunc(board, 0, i, n, m);
  }
  // last col
  for (i = 0; i < m; i++) {
    if (board[n - 1][i] == 'O')
      dfsFunc(board, n - 1, i, n, m);
  }

  // after the dfs is done we again make the #'s O's and return
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (board[i][j] == '#')
        board[i][j] = 'O';
      else
        board[i][j] = 'X';
    }
  }
  return;
}
int main() {
  vector<vector<char>> board = {
      {'X', 'X', 'X', 'X'},
      {'X', 'X', 'O', 'X'},
      {'X', 'O', 'X', 'X'},
      {'X', 'O', 'X', 'X'},
  };
  solve(board);
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}