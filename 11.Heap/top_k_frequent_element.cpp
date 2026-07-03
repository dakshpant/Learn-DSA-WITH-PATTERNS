#include <iostream>
#include <vector>
#include <functional>
#include <unordered_map>
#include <queue>
using namespace std;

struct min_min_cmp
{
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.first == b.first)
        {
            return a.second > b.second;
        }
        return a.first > b.first;
    }
};
vector<int> TopKFrequentElement(vector<int> &arr, int k)
{
    int n = arr.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, min_min_cmp> pq;

    unordered_map<int, int> f;

    for (int i = 0; i < n; i++)
        f[arr[i]]++;

    for (auto i : f)
    {
        int element = i.first;
        int freq = i.second;

        pair<int, int> curr = {freq, element};

        if (pq.size() < k)
        {
            pq.push(curr);
            continue;
        }

        if (curr.first < pq.top().first)
            continue;

        pq.pop();
        pq.push(curr);
    }
    vector<int> res;
    while (!pq.empty())
    {
        res.push_back(pq.top().second);
        pq.pop();
    }
    return res;
}
int main()
{
    vector<int> arr = {1, 2, 1, 2, 1, 2, 3, 1, 3, 2};
    int k = 2;

    vector<int> ans = TopKFrequentElement(arr, k);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    return 0;
}