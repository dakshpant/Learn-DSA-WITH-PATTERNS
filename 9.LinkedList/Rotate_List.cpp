#include <iostream>
using namespace std;

#define null NULL

struct Node
{
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {}
};
Node *rotateList(Node *head, int k)
{
    if (head == null)
        return head;
    Node *last = head;
    int n = 1;
    while (last->next != null)
    {
        n++;
        last = last->next;
    }
    // at this point we have the last node and total nodes in the tist ka count
    k = k % n;
    if (k == 0)
        return head;

    Node *t = head;
    int count = 1;

    while (t->next != null)
    {
        if (count == (n - k))
            break; // as we reach the t we comes out of loop

        count++;
        t = t->next; // incrementing t to get to the actual t or the new last node
    }

    last->next = head;   // makes the list circular by joining the last null to the current head
    Node *res = t->next; // new head is being assigned
    t->next = null;      // breaking the circular list by making the new last null
    return res;
}
int main()
{

    // creating list
    // 1 -> 2 -> 3 -> 4 -> 5

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original List:\n";

    Node *temp = head;

    while (temp != null)
    {
        cout << temp->val;

        if (temp->next != null)
            cout << " -> ";

        temp = temp->next;
    }

    cout << endl;

    int k = 2;

    head = rotateList(head, k);

    cout << "Rotated List:\n";

    temp = head;

    while (temp != null)
    {
        cout << temp->val;

        if (temp->next != null)
            cout << " -> ";

        temp = temp->next;
    }

    cout << endl;

    return 0;
}
