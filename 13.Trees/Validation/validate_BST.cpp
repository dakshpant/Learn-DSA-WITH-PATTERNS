#include <iostream>
using namespace std;
typedef struct Node {
  int val;
  Node *left;
  Node *right;
  Node(int val) : val(val), left(nullptr), right(nullptr) {}
  Node(int val, Node *left, Node *right) : val(val), left(left), right(right) {}
} Node;
Node *prevv = nullptr;
bool ans = true;
void func(Node *node) {
  if (node == nullptr)
    return;
  func(node->left);
  if (prevv == nullptr) {
    prevv = node;
  } else {
    if (node->val <= prevv->val) {
      ans = false;
    }
    prevv = node;
  }
  func(node->right);
  return;
}
bool isValisBST(Node *root) {
  prevv = nullptr;
  ans = true;
  func(root);
  return ans;
}
int main() {
  Node *root = new Node(4);

  root->left = new Node(2);
  root->right = new Node(6);

  root->left->left = new Node(1);
  root->left->right = new Node(3);

  root->right->left = new Node(5);
  root->right->right = new Node(7);

  cout << isValisBST(root) << endl; // Expected: 1 (true)

  return 0;
}
