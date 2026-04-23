#include<iostream>
using namespace std;
struct ListNode
{
    int var;
    ListNode *next;
    ListNode(int x) : var(x), next(null);
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
    return 0;
}
