#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int calcDistance(vector<int> &points)
{
    int x = points[0];
    int y = points[1];
    return x * x + y * y;
}
vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    int n = points.size();
    priority_queue<pair<int, int>> pq;

    for (int i = 0; i < n; i++)
    {
        int dist = calcDistance(points[i]);
        int index = i;

        pair<int, int> curr = {dist, index};
        if (pq.size() < k)
        {
            pq.push(curr);
            continue;
        }

        if (curr.first > pq.top().first)
            continue;

        if (curr.first < pq.top().first)
        {
            pq.pop();
            pq.push(curr);
        }
    }
    vector<vector<int>> res;
    while (!pq.empty())
    {
        res.push_back(points[pq.top().second]);
        pq.pop();
    }
    return res;
}
int main()
{
    vector<vector<int>> points = {{1, 3}, {-2, 2}};
    int k = 1;
    vector<vector<int>> ans = kClosest(points, k);
    ;
    for (auto i : ans)
    {
        cout << i[0] << "," << i[1] << endl;
    }
    return 0;
}