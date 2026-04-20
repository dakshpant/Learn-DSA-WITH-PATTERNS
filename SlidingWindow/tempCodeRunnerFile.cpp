#include <iostream>
#include<vector>
#include<string>
#include<climits>
using namespace std;

/*
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
*/

bool sahi(vector<int> &have, vector<int> &need){
    for(int i = 0; i < 256; i++){
        if(have[i] < need[i]){
            return false;
        }
    }
    return true;
}
string minSubstring(string s, string t){
    vector<int> have(256,0);
    vector<int> need(256,0);
    int h = 0; int l = 0;
    int res = INT_MAX;
    int start = -1;

    //Feeding the string t into the need array which is teh bareminimum requirement
    for(char c : t){
        need[c]++;
    }
    for(h=0;h<s.size();h++){
        //includeing the info into the vector to generate window
        have[s[h]]++;
        while(sahi(have, need)){
            int len = h - l + 1;
            /*
            since we want the least window as so if result is grater than the length of current window means teh current window is teh shorest*/
            if(res > len){
                res = len; //update the result with the min result possible
                start = l;//used later to prin the windo using string method substr(start,end)
            }
            have[s[l]]--;
            l++;
        }
    }
    return (res == INT_MAX ? "" : s.substr(start, res));
}
int main(){
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string ans = minSubstring(s,t);
    cout<< ans << endl;
    return 0;
}