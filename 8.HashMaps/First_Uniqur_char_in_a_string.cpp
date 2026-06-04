#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int uniqueChar(string s){
    int n = s.size();
    unordered_map<char, int> mpp;
    for(int i = 0; i < n; i++){
        mpp[s[i]]++;
    }
    for(int i = 0; i < n; i++){
        if(mpp[s[i]] == 1) return i;
    }
    return -1;
}
int main(){
    string s = "leetcode";
    int ans = uniqueChar(s);
    cout << ans << endl;
    return 0;
}