using namespace std;
#include<iostream>
#include<vector>
int findMin(vector<int> &arr){
    int n = arr.size();
    int low = 0; int high = n - 1;
    int res;
    while(low <= high){
        int guess = (high+low) / 2;
        if(arr[guess] > arr[n - 1]){
            low = guess + 1;
        }else{
            res = guess;
            high = guess - 1;
        }
    }
    return arr[res];
}
int main(){
    vector<int> arr = {4,5,6,7,0,1,2};
    int ans = findMin(arr);
    cout<<"The Min in the arr is:" << ans << endl;
    return 0;
}