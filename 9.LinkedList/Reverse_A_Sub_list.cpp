#include <iostream>
// #include <list> no need to this a defining own list
using namespace std;
struct Node
{

    int val;
    Node *next;
    Node() : val(0), next(nullptr) {};

    Node(int x) : val(x), next(nullptr) {};

    Node(int x, Node *next) : val(x), next(next) {}
};
void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

Node *
subListReversal(Node *head, int left, int right)
{
    if (head == NULL)
        return NULL;
    if (left == right)
        return head;

    Node *t = head;
    Node *before = NULL;
    int pos = 1;
    while (t != NULL)
    {
        // Condition to reach the left which is the starting of the sub-list
        if (pos < left)
        {
            before = t;
            t = t->next;
            pos++;
            continue;
        }

        // exited the if block means reached the left i.e t = left
        //  now the reversal starts

        Node *curr = t;
        Node *prev = NULL;
        int times = right - left + 1;
        while (times--)
        {
            Node *nxt = curr->next;
            curr->next = prev; // changes the direction of to prev forom next
            prev = curr;
            curr = nxt;
        }
        t->next = curr;
        if (before)
        {
            before->next = prev;
            return head;
        }
        head = prev;
        return head;
    }
    return head;
}
int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head = subListReversal(head, 2, 4);
    printList(head);
    return 0;
}