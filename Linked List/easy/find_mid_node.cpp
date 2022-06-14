// Concept
// We use Tortoise and Hare Approach
// Hare: moves with a speed (2x)
// Tortoise: moves with (1x) speed
// So when hare reaches end tortoise would be in its half way because hare is covering double distance than tortoise

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data=0;
    node* next;
    node(int value){
        data = value;
        next=NULL;
    }
};

void insertAtTail(node* &head, int value){
    if(head == NULL){
        node* temp = new node(value);
        head = temp;
        return;
    }

    node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    node* temp2 = new node(value);
    temp->next = temp2;
}


node* middleNode(node* head) {
    node* fast = head->next;
    node* slow = head;
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

int main()
{
    node*head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);

    node* mid = middleNode(head);
    cout << "Middle Node: " << mid->data;

    return 0;
}