#include <iostream>
#include <vector>
using namespace std;
int findCheapestFlight(int n, vector<vector<int>> &flights, int src, int dst,
                       int k) {
  vector<int> res(n, 1e8);
  res[src] = 0;
  for (int i = 0; i <= k; i++) {
    vector<int> tmp = res;
    for (int j = 0; j < flights.size(); j++) {
      int s = flights[j][0];
      int d = flights[j][1];
      int wt = flights[j][2];

      if (res[s] != 1e8 && tmp[d] > res[s] + wt) {
        tmp[d] = res[s] + wt;
      }
    }
    res = tmp;
  }
  if (res[dst] == 1e8)
    return -1;

  return res[dst];
}
int main() {
  int n = 4;
  int k = 1;
  int src = 0;
  int dst = 3;
  vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100},
                                 {1, 3, 600}, {2, 3, 200}, {0, 3, 1000}};
  cout << findCheapestFlight(n, flights, src, dst, k);
  return 0;
}