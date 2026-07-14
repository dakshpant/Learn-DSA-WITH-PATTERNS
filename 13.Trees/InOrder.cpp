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

  // In Order -> Left root(node) Right

  func(node->left, res);
  res.push_back(node->val);
  func(node->right, res);

  return;
}
vector<int> inOrder(TreeNode *root) {

  vector<int> res;
  func(root, res);
  return res;
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = nullptr;
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(3);

  vector<int> ans = inOrder(root);
  cout << "The In order Traversal is: ";
  for (auto i : ans) {
    cout << i << ", ";
  }
  
  cout << endl;

  return 0;
}