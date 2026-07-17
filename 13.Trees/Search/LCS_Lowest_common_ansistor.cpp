#include <cstddef>
#include <iostream>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) {
    val = x;
    left = NULL;
    right = NULL;
  }
};
int func(TreeNode *node, TreeNode *p, TreeNode *q, TreeNode *&ans) {
  if (node == NULL)
    return 0;
  int left = func(node->left, p, q, ans);
  int right = func(node->right, p, q, ans);
  int self = 0;
  if (node == p || node == q)
    self = 1;

  int total = left + right + self;

  if(total == 2 && ans == NULL) ans = node;

  return total;
}
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
  TreeNode *ans = NULL;
  func(root, p, q, ans);
  return ans;
}
int main() {
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(5);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(2);
  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(8);
  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(4);
  TreeNode *p = root->left;
  TreeNode *q = root->right;
  TreeNode *ans = lowestCommonAncestor(root, p, q);
  cout << ans->val << endl;
  return 0;
}