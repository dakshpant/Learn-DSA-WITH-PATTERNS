#include <iostream>
#include <vector>
using namespace std;
void printVec(vector<int> tmp) {
  cout << "{";
  for (auto i : tmp) {
    cout << i;
  }
  cout << "}";
}
void generateSubset(vector<int> a, int n, int idx, vector<int> tmp) {

  cout << "\nCALL -> idx: " << idx << " tmp: ";
  printVec(tmp);
  cout << endl;

  // base case
  if (idx == n) {
    printVec(tmp);
    cout << endl;
    return;
  }
  // recursive call
  // condition of not including current
  // not include
  cout << "SKIP element " << a[idx] << " at idx " << idx << endl;
  generateSubset(a, n, idx + 1, tmp);
  // condition of inclusion of current to the subset
  // include
  cout << "TAKE element " << a[idx] << " at idx " << idx << endl;
  tmp.push_back(a[idx]);

  cout << "After push tmp: ";
  printVec(tmp);
  cout << endl;

  generateSubset(a, n, idx + 1, tmp); // generating with inclusion

  cout << "BACKTRACK remove " << tmp.back() << " from tmp: ";

  printVec(tmp);
  cout << endl;

  tmp.pop_back(); // removes the element added above to not disturb other calls
                  // of the recursion

  cout << "After pop tmp: ";
  printVec(tmp);
  cout << endl;

  cout << "RETURN from idx " << idx << endl;

  return;
}
int main() {
  vector<int> a = {1, 2, 3};
  int n = a.size();
  int idx = 0;
  vector<int> tmp;
  generateSubset(a, n, idx, tmp);
  return 0;
}