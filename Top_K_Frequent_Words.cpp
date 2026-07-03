#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

struct min_max_cmp
{
    bool operator()(pair<int, string> &a, pair<int, string> &b)
    {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first > b.first;
    }
};
vector<string> Top_k_frequent_words(vector<string> &words, int k)
{
    int n = words.size();

    priority_queue<pair<int, string>, vector<pair<int, string>>, min_max_cmp> pq;
    unordered_map<string, int> f;

    for (int i = 0; i < n; i++)
    {
        f[words[i]]++;
    }

    for (auto i : f)
    {
        string element = i.first;
        int freq = i.second;
        pair<int, string> curr = {freq, element};
        if (pq.size() < k)
        {
            pq.push(curr);
            continue;
        }

        if (curr.first < pq.top().first)
            continue;

        if (curr.first > pq.top().first || (curr.first == pq.top().first && curr.second < pq.top().second))
        {
            pq.pop();
            pq.push(curr);
        }
    }
    vector<string> res;
    while (!pq.empty())
    {
        res.push_back(pq.top().second);
        pq.pop();
    }

    reverse(res.begin(), res.end());

    return res;
}

int main()
{
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    int k = 2;
    vector<string> ans = Top_k_frequent_words(words, k);
    for (auto i : ans)
    {
        cout << i << endl;
    }
    return 0;
}