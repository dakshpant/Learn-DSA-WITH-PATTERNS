#include<iostream>
#include<stack>
using namespace std;
vector<int> dailyTemperatures(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;
    ans[n-1] = 0;
    st.push(n-1);
    for(int i = n-2; i >=0; i--){
        while(!st.empty() && arr[st.top()] <= arr[i]){
            st.pop();
        }

        if(st.empty()){
            ans[i] = 0;
        }else{
            ans[i] = st.top() - i;
        }
        st.push(i);
    }
    return ans;
}
int main(){
    vector<int> arr = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> ans = dailyTemperatures(arr);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}