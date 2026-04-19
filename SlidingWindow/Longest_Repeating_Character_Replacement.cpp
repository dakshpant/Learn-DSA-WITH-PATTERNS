#include<iostream>
#include<string>
#include<vector>
#include<climits>
#include<unordered_map>
using namespace std;
//Function to chaeck maximum frequency of character in the array
/* 
Approach 1 :using a function to check frequency and then using sliding window
int find(vector<int> &a){
    int maxCount = -1;
    for(int i = 0; i < 256;i++){
        maxCount = max(maxCount, a[i]);
    }
    return maxCount;
}
int characterReplacement(string s, int k){
    int l = 0;
    int h = 0;
    int res = INT_MIN;
    vector<int> f(256,0);
    for(h=0;h<s.size();h++){
        f[s[h]]++;
        int maxCount = find(f);
        int len = h-l+1;
        int diff = len-maxCount;
        while(diff > k){
            f[s[l]]--;
            l ++;
            len = h-l+1;
            diff = len-maxCount;
        }
        res = max(res, len);
    }
    return res;
}*/
//Approach 2 using hashmap and sliding window
int characterReplacement(string s, int k){
    int l = 0;
    int h = 0;
    int res = INT_MIN;
    int count = -1;
    unordered_map<char,int> mpp;
    for (h = 0; h < s.size(); h++)
    {
        mpp[s[h]]++;
        count = max(count, mpp[s[h]]);
        int len = h-l+1;
        int diff = len-count;
        while(diff>k){
            mpp[s[l]]--;
            l++;
            len =h-l+1;
            diff=len-count;
        }
        res = max(res,len);
    }
    return res;
}

int main(){
    string s = "AABABBA";
    int k = 1;
    int ans = characterReplacement(s,k);
    cout<< ans << endl;
    return 0;
}