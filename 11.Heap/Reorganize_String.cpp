#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
string reorganizeString(string s)
{
    int n = s.size();
    int seat = 0;
    string res = "";

    unordered_map<char, int> f;
    priority_queue<pair<int, char>> pq;
    for (int i = 0; i < n; i++)
    {
        f[s[i]]++;
    }
    for (auto i : f)
    {
        pq.push({i.second, i.first});
    }

    while (!pq.empty())
    {
        pair<int, char> p = pq.top();
        pq.pop();

        if (seat == 0 || res[seat - 1] != p.second)
        {
            res.push_back(p.second);
            seat++;
            p.first--;

            if (p.first > 0)
                pq.push(p);
        }
        else
        {
            if (pq.empty())
                return "";

            pair<int, char> p2 = pq.top();
            pq.pop();
            res.push_back(p2.second);
            seat++;
            p2.first--;
            if (p2.first > 0)
                pq.push(p2);

            pq.push(p);
        }
    }
    return res;
}
int main()
{
    string s = "aaaabb";
    string ans = reorganizeString(s);
    cout << ans << endl;
    return 0;
}