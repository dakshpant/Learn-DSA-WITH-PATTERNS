#include<iostream>
#include<unordered_map>
#include<string>
#include<climits>
using namespace std;
int lengthOfLongestSubstring(string s){
int low = 0;
int high = 0;
int res = INT_MIN;
unordered_map<char, int> mpp;
for(high = 0; high < s.size(); high++){
    mpp[s[high]]++;
    int k = high-low+1;
    while(mpp.size()<k){
        mpp[s[low]]--;
        if(mpp[s[low]]==0){
            mpp.erase(s[low]);
        }
        low++;
    }
    int len = high-low+1;//re initializing the length cuz the change in low effects the window size
    res=max(res, len);
}
return (res==INT_MIN?0:res);
}
int main(){
    int ans = lengthOfLongestSubstring("abcabcbb");
    cout << ans;
    return 0;
}