#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    // Stores intervals after inserting newInterval
    vector<vector<int>> res;

    // Sort intervals based on starting time
    sort(intervals.begin(), intervals.end());

    // Flag to track whether newInterval is inserted or not
    bool inserted = false;

    // Traverse all intervals
    for (int i = 0; i < intervals.size(); i++)
    {

        int start = intervals[i][0];

        // Insert newInterval before the first interval
        // whose start is greater than or equal to newInterval start
        if (inserted == false && start >= newInterval[0])
        {
            res.push_back(newInterval);
            inserted = true;
        }

        // Push current interval
        res.push_back(intervals[i]);
    }

    // After traversing all intervals,
    // if newInterval is still not inserted,
    // it means either:
    // 1. intervals array was empty
    // 2. newInterval belongs at the end
    // so insert it now.
    if (inserted == false)
    {
        res.push_back(newInterval);
    }

    // Stores final merged intervals
    vector<vector<int>> res2;

    // Take first interval as current interval
    int s1 = res[0][0];
    int e1 = res[0][1];

    // Traverse remaining intervals for merging
    for (int i = 1; i < res.size(); i++)
    {

        int s2 = res[i][0];
        int e2 = res[i][1];

        // If intervals overlap,
        // extend the ending boundary
        if (e1 >= s2)
        {
            e1 = max(e1, e2);
            continue;
        }

        // No overlap:
        // store previous merged interval
        res2.push_back({s1, e1});

        // Move to next interval
        s1 = s2;
        e1 = e2;
    }

    // Push the last merged interval
    res2.push_back({s1, e1});

    return res2;
}

int main()
{
    vector<vector<int>> intervals = {{1,3}, {6,9}};
    vector<int> newInterval = {2,5};

    vector<vector<int>> ans = insert(intervals, newInterval);

    for(auto interval : ans)
    {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }

    return 0;
}