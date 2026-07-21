#include <iostream>
#include <vector>
using namespace std;
struct Node {
  int val;
  Node *left;
  Node *right;
  Node(int val) {
    this->val = val;
    this->left = nullptr;
    this->right = nullptr;
  }
};
int res = 0;
void func(Node *node, int sum) {
  if (node == nullptr)
    return;
  sum = sum * 10 + node->val;
  if (node->left == nullptr && node->right == nullptr) {
    res += sum;
    return;
  }
  func(node->left, sum);
  func(node->right, sum);
  return;
}
int sumNumbers(Node *root) {
  func(root, 0);
  return res;
}
int main() {
  Node *root = new Node(4);

  root->left = new Node(9);
  root->right = new Node(0);

  root->left->left = new Node(5);
  root->left->right = new Node(1);

  cout << "Sum = " << sumNumbers(root) << endl;

  return 0;
}