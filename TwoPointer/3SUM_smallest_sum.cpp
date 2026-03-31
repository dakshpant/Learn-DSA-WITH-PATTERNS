#include <bits/stdc++.h>
using namespace std;
long long countTriplets(int n, long long sum, long long arr[])
{
    sort(arr, arr + n);
    long long count = 0;

    for (int i = 0; i < n - 2; i++)
    {
        int left = i + 1;
        int right = n - 1;
        
        while (left < right)
        {
            long long curr_sum = arr[i] + arr[left] + arr[right];
            int diff = (right - left);
            if (curr_sum < sum)
            {
                count = count + diff;
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    return count;
}
int main()
{
    long long arr[] = {-2, 0, 1, 3};
    int n = 4;
    long long sum = 2;
    long long ans = countTriplets(n, sum, arr);
    cout << ans << endl;
    return 0;
}