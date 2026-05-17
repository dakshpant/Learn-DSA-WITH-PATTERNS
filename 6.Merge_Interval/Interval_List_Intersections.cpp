#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
vector<vector<int>> intersection(vector<vector<int>> &a, vector<vector<int>> &b){
    vector<vector<int>> res;
    int i = 0;
    int j = 0;
    while(i < a.size() && j < b.size()){
        int s1 = a[i][0]; int e1 = a[i][1];
        int s2 = b[j][0]; int e2 = b[j][1];
        //overlapping condition check for i > j normal cases sorted array 
        if(s1 <= s2){
            if(e1 >= s2){
                int s = max(s1, s2);
                int e = min(e1, e2);
                res.push_back({s,e});
            }
        }
        else//case for j > i
        {
            if(e2 >= s1){
                int s = max(s1, s2);
                int e = min(e1, e2);
                res.push_back({s,e});
            }
        }
        //i and j moment
        if(e1 <=  e2) i++;
        else j++;
    }
    return res;
}
int main(){
vector<vector<int>> a = {
        {0,2},
        {5,10},
        {13,23},
        {24,25}
    };

    vector<vector<int>> b = {
        {1,5},
        {8,12},
        {15,24},
        {25,26}
    };

    vector<vector<int>> ans = intersection(a,b);

    cout << "Intersection Intervals:\n";

    for(auto interval : ans){

        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }

}