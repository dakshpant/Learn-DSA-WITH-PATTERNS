#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
int minMeetingRooms(vector<int> &start, vector<int> &end)
{
    int n = start.size();
    int i = 0;
    int j = 0;
    int res = 0;
    int room = 0;
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    while (i < n && j < n)
    {
        if (start[i] < end[j]) // non-overlapping when equal
        {
            room++;
            res = max(res, room);
            i++;
        }
        else
        {
            room--;
            j++;
        }
    }
    return res;
}
int main()
{
    vector<int> start = {1, 3, 5};
    vector<int> end = {2, 6, 8};

    cout << minMeetingRooms(start, end);
    return 0;
}