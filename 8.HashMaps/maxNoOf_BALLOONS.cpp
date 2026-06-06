#include<iostream>
#include<climits>
#include<string>
#include<unordered_map>
using namespace std;
int ballons(string s){
    int n = s.size();
    unordered_map<char, int> have;
    while(n--){
        have[s[n]]++;
    }
    unordered_map<char, int> need;
    need['b'] = 1;
    need['a'] = 1;
    need['l'] = 2;
    need['o'] = 2;
    need['n'] = 1;
    int res = INT_MAX;
    for(auto i : need){
        char c = i.first;
        int freq_charInNeed = i.second;
        int freq_needChar_InHave = have[c];
        int times = freq_needChar_InHave/freq_charInNeed;
        res = min(res, times);
    }
    return res;
}
int main(){
    string s = "nlaebolko";
    int ans = ballons(s);
    cout << ans << endl;
    return 0;
}