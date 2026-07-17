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

void func(TreeNode *node, vector<int> &res) {
  if (node == NULL)
    return;

  // Pre Order -> root(node) Left Right

  res.push_back(node->val);
  func(node->left, res);
  func(node->right, res);

  return;
}
vector<int> preOrder(TreeNode *root) {

  vector<int> res;
  func(root, res);
  return res;
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = nullptr;
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(3);

  vector<int> ans = preOrder(root);
  cout << "The Pre order Traversal is: ";
  for (auto i : ans) {
    cout << i << ", ";
  }

  cout << endl;

  return 0;
}