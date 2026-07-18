#include <iostream>
using namespace std;
struct NodeTree {
  int val;
  NodeTree *left;
  NodeTree *right;
  NodeTree(int x) {
    val = x;
    left = NULL;
    right = NULL;
  }
};
NodeTree *ans = NULL;
void func(NodeTree *node, int val) {
  if (node == NULL) {
    return;
  }
  if (node->val == val) {
    ans = node;
    return;
  }
  if (node->val > val) {
    func(node->left, val);
  } else {
    func(node->right, val);
  }
}
NodeTree *searchBST(NodeTree *root, int val) {
  ans = NULL;
  func(root, val);
  return ans;
}
int main() {
  NodeTree *root = new NodeTree(4);
  root->left = new NodeTree(2);
  root->right = new NodeTree(6);
  root->left->left = new NodeTree(1);
  root->left->right = new NodeTree(3);
  root->right->left = new NodeTree(5);
  root->right->right = new NodeTree(7);
  NodeTree *ans = searchBST(root, 5);
  cout << ans->val << endl;
  return 0;
}