#include <iostream>
using namespace std;
struct Node
{
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {};
    Node(int x) : val(x), next(nullptr) {};
    Node(int x, Node *next) : val(x), next(next) {};
};

void reverse(Node *head, int times)
{
    Node *curr = head;
    Node *prev = NULL;
    while (times--)
    {
        Node *nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return;
}
Node *SwapPairs(Node *head)
{
    if (head == NULL)
        return head;

    Node *left = head;
    Node *right;
    Node *res = NULL;
    Node *prevLeft = NULL;
    int size = 2;
    while (true)
    {
        right = left;
        for (int i = 0; i < size - 1; i++)
        {
            if (right == NULL)
                break;
            right = right->next;
        }
        if (right)
        {
            Node *nextLeft = right->next;
            reverse(left, size);

            if (prevLeft)
                prevLeft->next = right;

            prevLeft = left;

            if (res == NULL)
                res = right;
            left = nextLeft;
        }
        else
        {
            if (prevLeft)
                prevLeft->next = left;

            if (res == NULL)
                return left;

            break;
        }
    }
    return res;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    Node *res = SwapPairs(head);
    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}