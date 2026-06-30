#include <iostream>
#include <vector>
using namespace std;

// Time Complexity Of helper fcn O(n+m)
int helperFindK(int n, int m, int guess)
{
    /*
    hERE WE FIND TEH COUNT FOR EACH GUESSED NUMBER BETWEEN THE SEARCH SPACE AND RETURN TO ITS LEXICAL SCOPE TO CHECK AGAINST THE K WHETHER IT MEETS THE REQUIREMENT IF YES SAVE AND MOVE TO FIND OTHER BEST POSSIBLE
    */

    int row = n;
    int col = 1; // why 1 in this case as in a multiplication matrix the 0 is not takes for obv reasons
    int count = 0;

    while (row >= 1 && col <= m)
    {
        if (row * col <= guess)
        {
            count += row;
            col++;
        }
        else
            row--;
    }
    return count;
}
// Time complexity is O(log(n+m))=> binary search
int findKthElement(int n, int m, int k)
{
    int low = 1;      // why one ? cuz the smallest no in a multiplication matrix is 1*1 =1
    int high = n * m; // why? cus the largest no is a multi matrix is m * n

    /*
    So our search space where we are finding the monotonicity is between {1 - m*n}
    */
    int res = -1;

    while (low <= high)
    {
        int guess = (low + high) / 2;

        int ans = helperFindK(n, m, guess);
        if (ans < k)
            low = guess + 1;
        else
        {
            res = guess;
            high = guess - 1;
        }
    }
    return res;
}
// Overall TC: O((n+m)log(nm))
int main()
{
    int m = 3;
    int n = 3;
    int k = 5;
    int ans = findKthElement(m, n, k);
    cout << "The ans for" << m << "x" << n << "is" << ans << endl;
    return 0;
}