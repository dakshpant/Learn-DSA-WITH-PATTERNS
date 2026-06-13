#include<iostream>
using namespace std;
#define null NULL
struct Node{
    int val;
    Node *next;
    Node(): val(0), next(nullptr){};
    Node(int x): val(x), next(nullptr){};
    Node(int x, Node *next): val(x), next(next){};
};
void rev(Node *head, int times){
    Node *curr = head;
    Node *prev = null;
    while(times--){
        Node* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return;
}
Node *reverseKGroup(Node *head, int k){
    if(head == null) return head;
    Node *left = head;
    Node *right;
    Node *res = null;
    Node *prevLeft = null;
    int size = k;
    while(true){
        right = left;
        for(int i = 0; i < size - 1; i++){
            if(right == null) break;
            right = right->next;
        }
        if(right){
            Node *nextLeft = right->next;
            rev(left, size);

            if(prevLeft){
                prevLeft->next = right;
            }
            prevLeft = left;

            if(res == null){
                res = right;
            }
            left = nextLeft;
        }
        else{
            if(prevLeft){
                prevLeft->next = left;
            }
            if(res == null){
                res = left;
            }

            break;
        }
    }
    return res;
}
int main(){

    Node *head = new Node(1);

    head->next = new Node(2);

    head->next->next = new Node(3);

    head->next->next->next = new Node(4);

    head->next->next->next->next = new Node(5);

    head->next->next->next->next->next = new Node(6);

    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);

    int k = 3;

    Node *res = reverseKGroup(head, k);

    while(res){

        cout << res->val << " ";

        res = res->next;
    }

    cout << endl;

    return 0;
}