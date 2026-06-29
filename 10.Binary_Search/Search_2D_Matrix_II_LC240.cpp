#include <iostream>
#include <vector>
using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int row = n - 1;
    int col = 0;
    while (row >= 0 && col < m)
    {
        if (matrix[row][col] == target)
            return true;
        else if (matrix[row][col] < target)
            col++;
        else
            row--;
    }
    return false;
}
int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 16;
    int ans = searchMatrix(matrix, target);
    if(ans == true)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}