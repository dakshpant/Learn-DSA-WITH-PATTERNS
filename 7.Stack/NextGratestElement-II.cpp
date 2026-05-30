#include<iostream>
#include<stack>
#include<vector>
using namespace std;

using namespace std;
vector<int> nextGreatestElement(vector<int> &arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;
    for(int i = n-2; i>=0; i--){
        st.push(arr[i]);
    }
    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i] = -1;
        }else{
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }
    return ans;
}
int main(){
    vector<int> arr = {1,2,1};
    vector<int> ans = nextGreatestElement(arr);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}