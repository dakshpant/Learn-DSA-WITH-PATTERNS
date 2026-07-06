#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int lastStoneWeight(vector<int> &stones)
{
    int n = stones.size();
    priority_queue<int> pq;
    for (auto i : stones)
        pq.push(i);

    while (pq.size() > 1)
    {
        int y = pq.top();
        pq.pop();
        int x = pq.top();
        pq.pop();

        if (x == y)
            continue;

        if (x != y)
        {
            pq.push(y - x);
        }
    }
    if (pq.empty())
        return 0;

    return pq.top();
}
int main()
{
    vector<int> stones = {2, 7, 4, 1, 8, 1};

    int ans = lastStoneWeight(stones);
    cout << ans << endl;
    return 0;
}