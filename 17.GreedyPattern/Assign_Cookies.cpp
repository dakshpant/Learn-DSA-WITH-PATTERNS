#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int assignCookie(vector<int> &child, vector<int> &cookiWt)
{
    int res = 0;
    sort(child.begin(), child.end());
    sort(cookiWt.begin(), cookiWt.end());
    int i = 0, j = 0;

    while (i < child.size() && j < cookiWt.size())
    {
        if (cookiWt[j] >= child[i])
        {
            res++;
            j++;
            i++;
        }
        else
            j++;
    }
    return res;
}
int main()
{
    vector<int> child = {};
    vector<int> cookieWt = {};
    cout << assignCookie(child, cookieWt);
    return 0;
}