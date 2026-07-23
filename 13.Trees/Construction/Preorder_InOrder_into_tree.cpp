#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
typedef struct Tree {
  int val;
  Tree *left;
  Tree *right;
  Tree(int x) : val(x), left(nullptr), right(nullptr) {};
} Tree;
unordered_map<int, int> inMap;
int idx = 0;
Tree *func(vector<int> &preorder, int low, int high) {
  if (low > high)
    return nullptr;

  Tree *root = new Tree(preorder[idx]);
  idx++;

  int position_Inorder = inMap[root->val];
  root->left = func(preorder, low,
                    position_Inorder - 1); // left subtree as per Inorder array
  root->right = func(preorder, position_Inorder + 1,
                     high); // right subtree as per Inorder array
  return root;
}
Tree *buildTree(vector<int> &preorder, vector<int> &inorder) {
  for (int i = 0; i < inorder.size(); i++) {
    inMap[inorder[i]] = i;
  }
  int low = 0;
  int high = inorder.size() - 1;
  return func(preorder, low, high);
}
void printLevelorder(Tree *root) {
  if (root == nullptr) {
    cout << "[]\n";
    return;
  }

  queue<Tree *> q;
  q.push(root);

  vector<string> ans;

  while (!q.empty()) {
    Tree *curr = q.front();
    q.pop();

    if (curr == nullptr) {
      ans.push_back("null");
    } else {
      ans.push_back(to_string(curr->val));
      q.push(curr->left);
      q.push(curr->right);
    }
  }

  // Remove trailing nulls (LeetCode doesn't print unnecessary nulls)
  while (!ans.empty() && ans.back() == "null") {
    ans.pop_back();
  }

  cout << "[";
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i];
    if (i != ans.size() - 1)
      cout << ",";
  }
  cout << "]\n";
}
int main() {
  vector<int> preorder = {3, 9, 20, 15, 7};
  vector<int> inorder = {9, 3, 15, 20, 7};

  Tree *root = buildTree(preorder, inorder);

  cout << "Inorder Traversal: ";
  printLevelorder(root);
  cout << endl;

  return 0;
}