#include <iostream>
#include <queue>
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

void printLevelOrder(TreeNode *root) {
  if (root == nullptr)
    return;

  queue<TreeNode *> q;
  q.push(root);

  cout << "[";

  while (!q.empty()) {
    TreeNode *node = q.front();
    q.pop();

    cout << node->val;

    if (!q.empty() || node->left || node->right)
      cout << ",";

    if (node->left)
      q.push(node->left);
    if (node->right)
      q.push(node->right);
  }

  cout << "]\n";
}
void func(TreeNode *node) {
  if (node == NULL)
    return;

  swap(node->left, node->right);
  func(node->left);
  func(node->right);
  return;
}
TreeNode *invertTree(TreeNode *root) {
  func(root);
  return root;
}
int main() {
  TreeNode *root =
      new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)),
                   new TreeNode(3, new TreeNode(5), new TreeNode(6)));
  TreeNode *ans = invertTree(root);
  printLevelOrder(ans);
  return 0;
}