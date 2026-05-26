#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
string removeDuplicates(string s) {
    stack<char> st;
    int n = s.size();
    string res;
    for(int i = 0; i < n; i++){
        if(st.empty()){
            st.push(s[i]);
        }else if(st.top() == s[i]){
            st.pop();
        }else{
            st.push(s[i]);
            // continue;
        }
    }
    while (!st.empty())
    {
        /* code */
        res.push_back(st.top());
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}
int main(){
    string s = "abbaca";
    string ans = removeDuplicates(s);
    cout<< "result" << ans;
    return 0;
}