#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
class Node
{
public:
    int value;
    int row;
    int col;
    Node(int v, int r, int c)
    {
        value = v;
        row = r;
        col = c;
    }
};
struct min_cmp
{
    bool operator()(const Node &a, const Node &b)
    {
        return a.value > b.value;
    }
};
vector<int> mergeArrays(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    priority_queue<Node, vector<Node>, min_cmp> pq;
    vector<int> res;

    for (int i = 0; i < n; i++)
        pq.push({mat[i][0], i, 0});

    while (!pq.empty())
    {
        Node n = pq.top();
        int v = n.value;
        int r = n.row;
        int c = n.col;

        pq.pop();
        res.push_back(v);

        if (c < m - 1)
        {
            pq.push({mat[r][c + 1], r, c + 1});
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> mat = {
        {1, 3, 5, 7},
        {2, 4, 6, 8},
        {0, 9, 10, 11}};
    vector<int> res = mergeArrays(mat);
    for (auto i : res)
    {
        cout << i << " ";
    }
    return 0;
}