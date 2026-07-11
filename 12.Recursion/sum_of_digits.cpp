#include <iostream>
using namespace std;
int sumOfDigits(int n) {

  if (n == 0)
    return 0;

  int d = n % 10;
  n = n / 10;
  int ans = sumOfDigits(n);
  return d + ans;
}
int main() {
  int n = 567;
  int ans = sumOfDigits(n);
  cout << ans;
  return 0;
}