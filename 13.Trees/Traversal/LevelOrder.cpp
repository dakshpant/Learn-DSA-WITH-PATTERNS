#include <iostream>
#include <queue>
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

vector<vector<int>> levelOrder(TreeNode *root) {
  vector<vector<int>> res;
  queue<TreeNode *> q;
  if (root == NULL)
    return {};
  q.push(root);

  while (!q.empty()) {
    int lvlSize = q.size();
    vector<int> tmp;
    while (lvlSize--) {
      TreeNode *t = q.front();
      q.pop();
      tmp.push_back(t->val);

      if (t->left != NULL)
        q.push(t->left);
      if (t->right != NULL)
        q.push(t->right);
    }
    res.push_back(tmp);
  }

  return res;
}
int main() {
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);

  vector<vector<int>> res = levelOrder(root);
  for (auto it : res) {
    for (auto it2 : it) {
      cout << it2 << " ";
    }
    cout << endl;
  }

  return 0;
}
