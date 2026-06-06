#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
//     int longestPalindrome(string s) {
//         int n=s.size();
//         unordered_map<char, int> f;
//         while(n--){
//             f[s[n]]++;
//         }
//         bool isOdd = false;
//         int res = 0;
//         for(auto i : f){
//             int val = i.second;
//             if(val%2 == 0) res += val;
//             else isOdd = true;//val %2 is not equal to 0 i.e 1 or else

//             if(isOdd == false) return res;
//         }
//         for(auto i : f){
//             int val = i.second;
//             if(val % 2 == 1) res += val - 1;

//         }
//             return res+1;
//     }

// Optimized above approach below
int longestPalendrome(string s){
    int n = s.size();
    unordered_map<char, int> mpp;
    while(n--){
        mpp[s[n]]++;
    }
    int res = 0;
    bool isOdd = false;
    for(auto i : mpp){
        int val = i.second;
        if(val % 2 == 0) res += val;
        else{
            res += val-1;
            isOdd = true;
        }
    }
    return isOdd ? res + 1 : res;
}
int main(){
    string s = "abccccdd";
    int ans = longestPalendrome(s);
    cout << "ans" << ans << endl;
    return 0;
}