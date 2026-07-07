#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int IPO(int k, int w, vector<int> &profits, vector<int> &capital)
{
    int n = profits.size();
    vector<pair<int, int>> proj;
    int idx = 0;
    priority_queue<int> pq;

    for (int i = 0; i < n; i++)
    {
        proj.push_back({capital[i], profits[i]});
    }
    sort(proj.begin(), proj.end());
    while (k--)
    {
        while (idx < n)
        {
            if (proj[idx].first > w)
                break;
            pq.push(proj[idx].second);
            idx++;
        }
        // edge case check that if teh heap is still empty that means the
        // min capital is grater that w so no project can be done hence ho profit can be made

        if (pq.empty())
            return w;

        w += pq.top();
        pq.pop();
    }
    return w;
}
int main()
{
    int k = 2;
    int w = 0;
    vector<int> profits = {1, 2, 3};
    vector<int> capital = {0, 1, 1};
    int ans = IPO(k, w, profits, capital);
    cout << ans << endl;
    return 0;
}

// Time complexity = O(n logn)//due to sorting
// Time Complexity = O(n);