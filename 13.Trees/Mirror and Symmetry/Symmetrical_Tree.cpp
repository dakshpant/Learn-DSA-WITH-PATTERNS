#include <iostream>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
bool func(TreeNode *root1, TreeNode *root2) {
  if (root1 == NULL && root2 == NULL)
    return true;
  if (root1 == NULL || root2 == NULL)
    return false;
  if (root1->val != root2->val)
    return false;

  bool r1 = func(root1->left, root2->right);
  bool r2 = func(root1->right, root2->left);
  return (r1 & r2);
}
bool symmetricTree(TreeNode *root) {
  bool ans = func(root->left, root->right);
  return ans;
}
int main() {
  TreeNode *root = new TreeNode(1);

  root->left = new TreeNode(2);
  root->right = new TreeNode(2);

  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);

  root->right->left = new TreeNode(4);
  root->right->right = new TreeNode(3);
  bool ans = symmetricTree(root);
  cout << ans;
  return 0;
}