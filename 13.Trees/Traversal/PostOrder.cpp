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

  // Post Order -> Left Right root(node)

  func(node->left, res);
  func(node->right, res);
  res.push_back(node->val);

  return;
}
vector<int> postOrder(TreeNode *root) {

  vector<int> res;
  func(root, res);
  return res;
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = nullptr;
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(3);

  vector<int> ans = postOrder(root);
  cout << "The Post order Traversal is: ";
  for (auto i : ans) {
    cout << i << ", ";
  }

  cout << endl;

  return 0;
}