//1186. Maximum Subarray Sum with One Deletion
/*
Given an array of integers, return the maximum sum for a non-empty subarray (contiguous elements) with at most one element deletion. In other words, you want to choose a subarray and optionally delete one element from it so that there is still at least one element left and the sum of the remaining elements is maximum possible.

Note that the subarray needs to be non-empty after deleting one element.

 

Example 1:

Input: arr = [1,-2,0,3]
Output: 4
Explanation: Because we can choose [1, -2, 0, 3] and drop -2, thus the subarray [1, 0, 3] becomes the maximum value.
 */
/*
int prevNoDel = noDel;
used for deleting the current value rather than deleting we simply skip that index value which gives a sense of deletion 
*/
#include <iostream>
#include<vector>
#include<climits>
using namespace std;
int maximumSumOneDel(vector<int> &arr){
    int noDel = arr[0];
    int oneDel = 0;
    int res = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        int prevNoDel = noDel;
        noDel = max(noDel + arr[i], arr[i]);
        oneDel = max(prevNoDel, oneDel + arr[i]);
        res = max(res, max(noDel, oneDel));
    }
    return res;
}
int main(){
    vector<int> arr = {1,-2,0,3};
    int ans = maximumSumOneDel(arr);
    cout<<ans<<endl;
    return 0;
}