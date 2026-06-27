#include <iostream>
#include <vector>
#include <climits>
using namespace std;
bool allocateBook(vector<int> &arr, int n, int k, int guess)
{
    int std = 1;
    int books = 0;
    for (int i = 0; i < n; i++)
    {
        // calculating the books to be allocated to current student initially 1
        if (books + arr[i] <= guess)
        {
            books += arr[i];
        } // Current student cannot take this book without exceeding 'guess',
        // so assign the book to the next student.
        else
        {
            std++;           // Move to the next student
            books = arr[i]; // The new student starts with the current book i.e the current value if arr[i]
        }

        if (std > k)
            return false; // More than k students are required
    }
    return true; // All books can be allocated using at most k students
}
int findBook(vector<int> &arr, int k)
{
    int n = arr.size();
    if (n < k)
        return -1;
    int low = 0;
    int high = 0;
    for (int i = 0; i < n; i++)
    {
        low = max(low, arr[i]);
        high += arr[i];
    }
    int res = -1;

    while (low <= high)
    {
        int guess = (low + high) / 2;

        if (allocateBook(arr, n, k, guess) == true)
        {
            res = guess;
            high = guess - 1;
        }
        else
        {
            low = guess + 1;
        }
    }
    return res;
}
int main()
{
    vector<int> arr = {10, 20, 30, 40, 50};
    int n = 2;
    int k = 3;
    int ans = findBook(arr, k);
    cout << ans << endl;
    return 0;
}