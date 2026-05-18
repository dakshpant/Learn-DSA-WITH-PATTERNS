#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;
bool overlapping(vector<vector<int>>&arr){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    int s1 = arr[0][0];
    int e1 = arr[0][1];
    for(int i = 1; i < n; i++){
        int s2 = arr[i][0];
        int e2 = arr[i][1];
        if(e1 >= s2){
            return true;
        }
        s1 = s2;
        e1 = max(e1,e2);
    } 
    return false; 
}
int main(){
    vector<vector<int>> arr = {
        {1,3},
        {5,7},
        {2,4}
    };

    if(overlapping(arr)) {
        cout << "Overlapping intervals exist";
    } else {
        cout << "No overlapping intervals";
    }
    return 0;
}