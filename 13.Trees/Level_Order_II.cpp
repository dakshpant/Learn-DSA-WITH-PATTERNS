#include <algorithm>
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
  TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

vector<vector<int>> LevelOrderII(TreeNode *root) {
  queue<TreeNode *> q;
  if (root == NULL)
    return {};

  q.push(root);
  vector<vector<int>> res;

  while (!q.empty()) {
    int lvlSize = q.size();
    vector<int> tmp;
    while (lvlSize--) {
      TreeNode *f = q.front();
      q.pop();
      tmp.push_back(f->val);
      if (f->left != NULL)
        q.push(f->left);
      if (f->right != NULL)
        q.push(f->right);
    }
    res.push_back(tmp);
  }
  reverse(res.begin(), res.end());
  return res;
}
int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);
  vector<vector<int>> res = LevelOrderII(root);
  for (auto it : res) {
    for (auto it1 : it) {
      cout << it1 << " ";
    }
    cout << endl;
  }
  return 0;
}