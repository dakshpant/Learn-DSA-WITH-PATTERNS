#include<iostream>
#include<stack>
#include<string>
using namespace std;
//Mathod 1 Mu way but lefts one edge case of " {]}" where ] is lef behind edge case
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
bool isValid(string s2) {
        stack<char> st;
        for (int i = 0; i < s2.size(); i++) {
            if (s2[i] == '(' || s2[i] == '{' || s2[i] == '[') {
                st.push(s2[i]);
            } else {
                if (st.empty())
                    return false;
                if (s2[i] == ')' && st.top() == '(' ||
                    s2[i] == '}' && st.top() == '{' ||
                    s2[i] == ']' && st.top() == '[') {
                    st.pop();
                }else{
                    return false;//mis match condition  "(])" => ] => fasle
                }
            }
        }
        if (!st.empty())
            return false;
        return true;
    }

int main(){
    string s = "([)]";
    string s2 = "{]}";
    bool ans1 = validetParentheses(s);
    bool ans2 = isValid(s2);
    cout<< ans1 << endl;
    cout<< ans2 << endl;
    return 0;
}