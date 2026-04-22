#include <iostream>
using namespace std;

// Definition of ListNode
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// Function to detect cycle
bool hasCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // move 1 step
        fast = fast->next->next;    // move 2 steps

        if (slow == fast) {         // cycle found
            return true;
        }
    }

    return false;  // no cycle
}

int main() {
    // Creating linked list: [3,2,0,-4]
    ListNode* head = new ListNode(3);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(0);
    ListNode* fourth = new ListNode(-4);

    // Linking nodes
    head->next = second;
    second->next = third;
    third->next = fourth;

    // 🔁 Create cycle (pos = 1)
    fourth->next = second;

    // Test
    if (hasCycle(head)) {
        cout << "Cycle detected" << endl;
    } else {
        cout << "No cycle" << endl;
    }

    return 0;
}