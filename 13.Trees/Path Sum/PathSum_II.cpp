#include <iostream>
#include <vector>
using namespace std;
struct Node {
  int val;
  Node *left;
  Node *right;
  Node(int val) {
    this->val = val;
    this->left = nullptr;
    this->right = nullptr;
  }
};
vector<vector<int>> res; // global result
void func(Node *root, int targetSum, int sum, vector<int> &diary) {
  if (root == nullptr)
    return;
  sum = sum + root->val;
  diary.push_back(root->val);
  if (root->left == nullptr && root->right == nullptr) {
    if (sum == targetSum)
      res.push_back(
          diary); // if sum == target and leafnode is hit means the path is a
                  // valid path so whatver is in the diary the path becomed a
                  // valid and hence pushing to res vector
    diary.pop_back(); // after pushin diary to res array we removes/ resets it
    // to save new path
    return;
  }
  func(root->left, targetSum, sum, diary);
  func(root->right, targetSum, sum, diary);
  diary.pop_back();
  return;
}
vector<vector<int>> pathSum(Node *root, int targetSum) {
  vector<int> diary;
  func(root, targetSum, 0, diary);
  return res;
}
int main() {
  Node *root = new Node(5);

  root->left = new Node(4);
  root->right = new Node(8);

  root->left->left = new Node(11);

  root->right->left = new Node(13);
  root->right->right = new Node(4);

  root->left->left->left = new Node(7);
  root->left->left->right = new Node(2);

  root->right->right->left = new Node(5);
  root->right->right->right = new Node(1);

  int targetSum = 22;

  vector<vector<int>> ans = pathSum(root, targetSum);
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}