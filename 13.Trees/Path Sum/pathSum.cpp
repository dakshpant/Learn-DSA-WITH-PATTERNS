#include <exception>
#include <iostream>
using namespace std;
struct Node {
  int val;
  Node *left;
  Node *right;
  Node(int val) {
    this->val = val;
    this->left = NULL;
    this->right = NULL;
  }
};
bool res = false;
void func(Node *node, int sum, int targetSum) {
  if (node == nullptr)
    return;

  sum += node->val;
  if (node->left == nullptr && node->right == nullptr) {
    if (sum == targetSum)
      res = true;
    return;
  }

  func(node->left, sum, targetSum);
  func(node->right, sum, targetSum);

  return;
}
bool PathSum(Node *root, int targetSum) {
  func(root, 0, targetSum);
  return res;
}
int main() {
  Node *root = new Node(5);
  root->left = new Node(4);
  root->right = new Node(8);
  root->left->left = new Node(11);
  root->right->left = new Node(13);
  root->right->right = new Node(4);
  root->left->left->left = new Node(7);
  root->left->left->right = new Node(2);
  root->right->right->right = new Node(1);
  int targetSum = 22;
  cout << PathSum(root, targetSum) << endl;
  return 0;
}