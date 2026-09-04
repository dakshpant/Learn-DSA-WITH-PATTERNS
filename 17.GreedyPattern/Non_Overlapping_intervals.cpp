#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
static bool cmp(vector<int>&a, vector<int>&b){
    return a[1] < b[1];
}
int eraseNonOverlapping(vector<vector<int>> &intervals){
  int n = intervals.size();
  sort(intervals.begin(),intervals.end(), cmp);
  int count = 1;
  int lastEnd = intervals[0][1];
  for(int i = 1; i < n; i++){
    if(intervals[i][0] >= lastEnd){
        count ++;
        lastEnd = intervals[i][1];
    }
  }
  return n - count;
}
int main() {
  vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
  cout << eraseNonOverlapping(intervals);
  return 0;
}