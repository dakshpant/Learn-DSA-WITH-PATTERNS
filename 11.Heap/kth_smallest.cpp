#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int kthSmallest(vector<int> &arr, int k){
    int n = arr.size();
    priority_queue<int> pq;
    for(int i = 0; i < k; i++){
        pq.push(arr[i]);
    }
    for(int i = k; i < n; i++){
        if(arr[i] >= pq.top()) continue;

        pq.pop();
        pq.push(arr[i]);
    }
    return pq.top();
}
int main(){
    vector<int> arr = {10, 5, 4, 3, 48, 6, 2, 33, 53, 10};
    int k = 4;
    int ans = kthSmallest(arr, k);
    cout << ans << endl;
    return 0;
}