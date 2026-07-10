#include <iostream>
using namespace std;
int fib(int n) {
  // base Case
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;

  // recursive case
  int ans_1 = fib(n - 1);
  int ans_2 = fib(n - 2);

  return ans_1 + ans_2;
}
int main() {
  int n = 6;
  int ans = fib(6);
  cout << ans;
  return 0;
}