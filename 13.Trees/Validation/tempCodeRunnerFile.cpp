#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef struct Node {
  int val;
  Node *left;
  Node *right;
  Node(int data) : val(data), left(nullptr), right(nullptr) {}
  Node(int data, Node *left, Node *right)
      : val(data), left(left), right(right) {}
} Node;
int res = 0;
int func(Node *root) {
  if (root == nullptr)
    return 0;

  int left = func(root->left);
  int right = func(root->right);

  int diameter = left + right;

  res = max(res, diameter);

  return 1 + max(left, right);
}
int diameterOfBST(Node *root) {
  res = 0;
  func(root);
  return res;
}
int main() {
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  cout << diameterOfBST(root) << endl;
  return 0;
}