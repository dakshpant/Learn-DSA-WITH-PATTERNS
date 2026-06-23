#include<iostream>
#include<vector>
using namespace std;
int peakIndex(vector<int> &a){
    int n = a.size();
    int low = 0;
    int high = n - 1;
    int peakIndex ;
    while(low <= high){
        int mid = (low + high) / 2;
        if(a[mid] < a[mid+1]){//peak is to the right of mid => Dhalan
            low = mid + 1;
        }else{//peak is to the left of mid => Chadai
            peakIndex = mid;
            high = mid - 1;
        }
    }
    return peakIndex ;
}
int main(){
    vector<int> a = {3,4,5,1};
    int ans = peakIndex(a);
    cout<<ans;
    return 0;
}