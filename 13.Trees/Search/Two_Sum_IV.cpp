#include <cstddef>
#include <iostream>
#include <stack>
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
stack<TreeNode *> asc;
stack<TreeNode *> desc;
TreeNode *getSmall() {
  if (asc.empty())
    return nullptr;
  TreeNode *small = asc.top();
  asc.pop();
  TreeNode *rightChild = small->right;
  while (rightChild) {
    asc.push(rightChild);
    rightChild = rightChild->left;
  }
  return small;
}
TreeNode *getBig() {
  if (desc.empty())
    return NULL;
  TreeNode *big = desc.top();
  desc.pop();
  TreeNode *leftChild = big->left;
  while (leftChild) {
    desc.push(leftChild);
    leftChild = leftChild->right;
  }
  return big;
}
bool TwoSum(TreeNode *root, int target) {
  if (root == nullptr)
    return false;
  TreeNode *t = root;
  while (t) {
    asc.push(t);
    t = t->left;
  }
  t = root;
  while (t) {
    desc.push(t);
    t = t->right;
  }

  TreeNode *i = getSmall();
  TreeNode *j = getBig();

  while (i && j && i != j) {
    int sum = i->val + j->val;
    if (sum == target) {
      return true;
    }
    if (sum < target) {
      i = getSmall();
    } else {
      j = getBig();
    }
  }

  return false;
}
int main() {

  int target = 9;

  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(3);
  root->right = new TreeNode(6);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(4);
  root->right->right = new TreeNode(7);

  cout << (TwoSum(root, target)) << endl;

  return 0;
}