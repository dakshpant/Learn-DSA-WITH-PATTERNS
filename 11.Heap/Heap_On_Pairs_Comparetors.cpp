// TO perform heap on pairs we need to change the comparator function of the heap to compare the first element of the pair and not the second element

// Min heap on first, Min on second
// note the data type can be changed as per the requirement
struct Min_Min_cmp
{
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first > b.first;
    }
};

// Min heap on first, Max on second
struct Min_Max_cmp
{
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first > b.first;
    }
}

// Max heap on first, Min on second

struct Max_Max_cmp
{
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    }
};

// Max heap on first, Max on second

struct Ma_Min_cmp
{
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    }
};
