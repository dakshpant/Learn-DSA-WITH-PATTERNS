//ques: 142.Linked List Cycle II 
// https://leetcode.com/problems/linked-list-cycle-ii/description/
#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode * detectCycle(ListNode *head){
    ListNode *slow = head;
    ListNode *fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){//as we found the cycle we reset the slow to the head again to get to the cycle
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}
int main(){
     // Create list: [3,2,0,-4]
    ListNode* head = new ListNode(3);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(0);
    ListNode* fourth = new ListNode(-4);

    // Link nodes
    head->next = second;
    second->next = third;
    third->next = fourth;

    // 🔁 Create cycle (pos = 1 → node with value 2)
    fourth->next = second;

    // Detect cycle start
    ListNode* result = detectCycle(head);

    if(result != NULL){
        cout << "Cycle starts at node with value: " << result->val << endl;
    } else {
        cout << "No cycle" << endl;
    }
    return 0;
}