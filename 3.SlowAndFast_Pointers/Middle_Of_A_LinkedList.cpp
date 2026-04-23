#include<iostream>
using namespace std;
struct ListNode
{
    int var;
    ListNode *next;
    ListNode(int x) : var(x), next(NULL) {};
};
ListNode *findMiddle(ListNode *head){
    ListNode *slow = head;
    ListNode *fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
int main(){
    // Create: 1 → 2 → 3 → 4 → 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* mid = findMiddle(head);

    cout << "Middle node value: " << mid->var << endl;

    return 0;
}
