#include <algorithm>
#include <cstddef>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
  int val;
  Node *next;
  Node() : val(0), next(nullptr) {}
  Node(int x) : val(x), next(nullptr) {}
  Node(int x, Node *next) : val(x), next(next) {}
};

struct min_cmp {
  bool operator()(Node *a, Node *b) { return a->val > b->val; }
};
Node *mergeKLists(vector<Node *> &lists) {
  priority_queue<Node *, vector<Node *>, min_cmp> pq;
  for (auto node : lists) {
    if (node != NULL)
      pq.push(node); // basically null is also a node in list so to
                     // prevent that to be pusde this is a check
  }

  Node res(0); // basically 0 is here to help initialise a result List
               // will skip this in final ans
  Node *tail = &res;

  while (!pq.empty()) {
    Node *curr = pq.top();
    pq.pop();

    tail->next = curr; // basically we are adding the current list to
                       // the result list
    // 0->null and 1(this we popped) after this => 0->1->null something
    // like this
    tail = tail->next; // basically moving the tail to teh next from 0
                       // to the newly added node

    if (curr->next != NULL) {
      pq.push(curr->next); // basically [1,4,5] this is teh set of
                           // list amongst the array list
      // what is happening is of there is anotehr node to the current
      // element(top) then aafter the pop of the top's next element
      // gets pushed to the heap thsi is that
    }
  }
  return res.next;
}

int main() {
  Node *l1 = new Node(1);
  l1->next = new Node(4);
  l1->next->next = new Node(5);

  Node *l2 = new Node(1);
  l2->next = new Node(3);
  l2->next->next = new Node(4);

  Node *l3 = new Node(2);
  l3->next = new Node(6);

  vector<Node *> lists = {l1, l2, l3};

  Node *res = mergeKLists(lists);

  while (res != NULL) {
    cout << res->val << " ";
    res = res->next;
  }
  cout << endl;
  return 0;
}
