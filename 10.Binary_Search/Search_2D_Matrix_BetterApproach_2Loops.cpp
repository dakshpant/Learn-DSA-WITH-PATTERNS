#include <iostream>
#include <vector>
using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();

    // searching the row first which might contain the target
    int low = 0;
    int high = n - 1;
    int row = -1;
    while (low <= high)
    {
        int guessRow = (low + high) / 2;
        if (matrix[guessRow][0] <= target)
        {
            row = guessRow;
            low = guessRow + 1;
        }
        else
        {
            high = guessRow - 1;
        }
    }
    // if teh row not found then return false else search for the target in that row
    if (row == -1)
        return false;

    low = 0;
    high = m - 1;
    while (low <= high)
    {
        int guessCol = (low + high) / 2;
        if (matrix[row][guessCol] == target)
            return true;
        else if (matrix[row][guessCol] < target)
            low = guessCol + 1;
        else
            high = guessCol - 1;
    }
    return false;
}
int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 16;
    int ans = searchMatrix(matrix, target);
    cout << ans << endl;
    return 0;
}