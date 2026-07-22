#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;
typedef struct Node {
  int val;
  Node *left;
  Node *right;
  Node(int x) : val(x), left(nullptr), right(nullptr) {};
  Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {};
} Node;

int galat = 0;
Node *prevv = nullptr;
Node *g1_first = nullptr;
Node *g1_second = nullptr;
Node *g2_first = nullptr;
Node *g2_second = nullptr;

void func(Node *node) {
  if (node == nullptr)
    return;
  func(node->left);
  if (prevv == nullptr)
    prevv = node;
  else {
    if (node->val < prevv->val) {
      if (galat == 0) {
        g1_first = prevv;
        g1_second = node;
        galat++;
      } else {
        g2_first = prevv;
        g2_second = node;
        galat++;
      }
    }
  }
  prevv = node;
  func(node->right);
  return;
}
void recoverBST(Node *root) {
  func(root);
  if (galat == 1)
    swap(g1_first->val, g1_second->val);
  else
    swap(g1_first->val, g2_second->val);
  return;
}
void inorder(Node *node) {
  if (node == nullptr)
    return;

  inorder(node->left);
  cout << node->val << " ";
  inorder(node->right);
}
int main() {
  Node *root = new Node(3);

  root->left = new Node(1);
  root->right = new Node(4);
  root->right->left = new Node(2);

  /*
          3
         / \
        1   4
           /
          2

     Inorder: 1 3 2 4
     Nodes 2 and 3 are swapped.
  */

  cout << "Before: ";
  inorder(root);
  cout << endl;

  recoverBST(root);

  cout << "After: ";
  inorder(root);
  cout << endl;

  return 0;
}
