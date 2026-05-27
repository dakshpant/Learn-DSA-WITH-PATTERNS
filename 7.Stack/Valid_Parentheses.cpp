#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool validetParentheses(string s){
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i]=='[' || s[i] == '{' || s[i] == '('){
            st.push(s[i]);
        }else if(st.empty()){
            return false;
            
        }else if(s[i]==']' && st.top() == '[' || s[i] == '}' && st.top() == '{' || s[i] == ')' && st.top() == '('){
            st.pop();
            continue;
        }
    }
    if(!st.empty()){
        return false;
    }
    
    return true;
}
int main(){
    string s = "([)]";
    bool ans = validetParentheses(s);
    cout<< ans << endl;
    return 0;
}