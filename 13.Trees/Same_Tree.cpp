#include <cstddef>
#include <iostream>
#include <vector>
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
bool isSameTree(TreeNode *root1, TreeNode *root2) {
  if (root1 == NULL && root2 == NULL)
    return true;
  if (root1 == NULL || root2 == NULL)
    return false;

  if (root1->val != root2->val)
    return false;

  bool r1 = isSameTree(root1->left, root2->left);
  bool r2 = isSameTree(root1->right, root2->right);

  if (r1 == true && r2 == true) {
    return true;
  }
  return false;
}
int main() {
  TreeNode *root1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
  TreeNode *root2 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
  bool ans = isSameTree(root1, root2);
  cout << ans;
  return 0;
}