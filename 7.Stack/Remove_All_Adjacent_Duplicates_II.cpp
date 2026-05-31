#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
string removeDuplicates(string s, int k)
{
    int n = s.size();
    stack<pair<char, int>> st;
    string res;
    for (int i = 0; i < n; i++)
    {
        char c = s[i];
        if (st.empty())
        {
            st.push({c, 1});
            continue;
        }
        if (!st.empty() && st.top().first != c)
        {
            st.push({c, 1});
            continue;
        }

        if (st.top().second < k - 1)
        {
            pair<char, int> p = st.top();
            st.pop();
            st.push({p.first, p.second + 1});
            continue;
        }
        st.pop(); // when st is not empty and st.second == k-1
        /**
         * means that the letter has occured k-1 times in atack and +1 is there in the array
         * which combines == k times hemeans we have to remove top
         */
    }
    while (!st.empty())
    {
        pair<char, int> p = st.top();
        st.pop();
        while (p.second--)
        {
            res.push_back(p.first);
        }
    }
    // since stack retruns in reverse orver order
    reverse(res.begin(), res.end());
    return res;
}
int main()
{
    int k = 2;
    string s = {"AABABBA"};
    string ans = removeDuplicates(s, k);
    cout << ans << endl;
    return 0;
}