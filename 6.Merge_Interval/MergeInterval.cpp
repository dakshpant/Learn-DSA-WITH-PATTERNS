#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
vector<vector<int>> mergeInterval(vector<vector<int>>& arr){
sort(arr.begin(),arr.end());
vector<vector<int>> res;
int s1 = arr[0][0];
int e1 = arr[0][1];
for(int i = 1; i < arr.size(); i++){
    int s2 = arr[i][0];
    int e2 = arr[i][1];
    if(e1 >= s2){
        e1 = max(e1, e2);
        continue;//if nit using continue then use else for below steps
    }
    res.push_back({s1,e1});
    s1 = s2;
    e1 = e2;
}
res.push_back({s1,e1});
return res;
}
int main() {
    vector<vector<int>> arr = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    
    vector<vector<int>> ans = mergeInterval(arr);

    // printing result
    for (auto interval : ans) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }

    return 0;
}