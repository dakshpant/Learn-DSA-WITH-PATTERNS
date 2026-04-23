#include<iostream>
#include<string>
#include<unordered_map>
#include<climits>
using namespace std;
int longestKSunString(string &s, int k){
    int low = 0;
    int high = 0;
    int res = INT_MIN;
    unordered_map<char, int> mpp;
    for(high = 0; high < s.size(); high++){
        mpp[s[high]]++;
        while(mpp.size() > k){
            mpp[s[low]]--;
            low++;
            if(mpp[s[low-1]]==0){
                mpp.erase(s[low-1]);
            }
        }
        if(mpp.size()==k){
            int len = high-low+1;
            res = min(res, len);
        }
    }
    return (res == INT_MIN ? -1 : res);
}
int main(){
char s = "aabacbebebe";
int k  = 3;
int ans =longestKSunString(s,k);
cout<< ans << endl;
    return 0;
}