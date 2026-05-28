#include<iostream>
#include<stack>
using namespace std;
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        stack<int> st;
        res[n-1] = -1;
        st.push(nums[n-1]);
        for(int i = n-2; i >= 0; i--){
            while(!st.empty() && st.top() <= nums[i]){
                st.pop();
            }
            if(st.empty()){ res[i] = -1;}
            else{
                res[i] = st.top();
            }
            st.push(nums[i]);
        }
        return res;
    }
    int main(){
        vector<int> nums = {4, 5, 2, 1, 3};
        vector<int> res = nextGreaterElements(nums);
        for(int i = 0; i < res.size(); i++){
            cout<<res[i]<<" ";
        }
        return 0;
    }