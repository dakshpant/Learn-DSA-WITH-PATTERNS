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
TreeNode *ans = NULL;
void func(TreeNode *node, TreeNode *p, TreeNode *q) {
  if (node == NULL)
    return;

  if (node == p || node == q) {
    ans = node;
    return;
  }
  if (node->val < p->val)
    func(node->right, p, q);
  else if (node->val > q->val)
    func(node->left, p, q);
  else {
    ans = node;
    return;
  }
}
TreeNode *LCA_Of_BST(TreeNode *node, TreeNode *p, TreeNode *q) {
  ans = NULL;
  if (p->val < q->val)
    func(node, p, q);
  else
    func(node, q, p);
  return ans;
}
int main() {
  TreeNode *root = new TreeNode(6);

  root->left = new TreeNode(2);
  root->right = new TreeNode(8);

  root->left->left = new TreeNode(0);
  root->left->right = new TreeNode(4);

  root->right->left = new TreeNode(7);
  root->right->right = new TreeNode(9);

  root->left->right->left = new TreeNode(3);
  root->left->right->right = new TreeNode(5);

  // LeetCode Example 1
  TreeNode *p = root->left;  // 2
  TreeNode *q = root->right; // 8

  TreeNode *ans = LCA_Of_BST(root, p, q);

  if (ans)
    cout << ans->val << endl;

  return 0;
}