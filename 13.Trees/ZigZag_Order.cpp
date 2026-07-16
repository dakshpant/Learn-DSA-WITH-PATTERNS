#include <cstddef>
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

vector<vector<int>> ZigZagOrder(TreeNode *root) {
  vector<vector<int>> res;
  queue<TreeNode *> q;
  if (root == NULL)
    return {};
  q.push(root);
  bool LToR = 1;
  while (!q.empty()) {
    int lvlSize = q.size();
    int first = 0;
    int last = lvlSize - 1;
    vector<int> tmp(
        lvlSize); // in this ques we are are creating tmp arr wfor specific size
                  // and simply replacing teh valus at teh required index where
                  // as in the Normal Leverl Order we are pushBacking the valuse
                  // this is teh reason for the lvlSize in tmp creation
    while (lvlSize--) {
      TreeNode *t = q.front();
      q.pop();
      if (LToR == 1) { // if flag is true then we are adding the values from
                       // left to right
        tmp[first] = t->val;
        first++;
      } else { // if flag is false then we are adding the values from right to
               // left
        tmp[last] = t->val;
        last--;
      }
      if (t->left != NULL)
        q.push(t->left);
      if (t->right != NULL)
        q.push(t->right);
    }
    res.push_back(tmp);
    LToR = 1 - LToR; // reversing the flag for the next iteration
  }
  return res;
}
int main() {
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);

  vector<vector<int>> res = ZigZagOrder(root);
  for (auto it : res) {
    for (auto it2 : it) {
      cout << it2 << " ";
    }
    cout << endl;
  }

  return 0;
}
