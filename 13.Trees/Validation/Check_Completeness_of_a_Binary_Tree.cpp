#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Node {
  int val;
  Node *left;
  Node *right;
  Node(int val) : val(val), left(nullptr), right(nullptr) {}
  Node(int val, Node *left, Node *right) : val(val), left(left), right(right) {}
};
bool isComplete(Node *root) {
  if (root == nullptr)
    return true;
  queue<Node *> q;
  q.push(root);
  bool nullAppeared = false;
  while (!q.empty()) {
    Node *t = q.front();
    q.pop();
    if (t == nullptr)
      nullAppeared = true;
    else {
      if (nullAppeared == true)
        return false;
      q.push(t->left);
      q.push(t->right);
    }
  }
  return true;
}
int main() {
  /*          1          */
  /*      /      \       */
  /*     2        3      */
  /*    /   \     /      */
  /*   4     5   6       */
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  cout << isComplete(root) << endl;
  return 0;
}