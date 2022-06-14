#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data=0;
    Node* next;
    Node* prev;
    Node* child;
    Node(int value){
        data = value;
        next=NULL;
        prev=NULL;
        child=NULL;
    }
};

void display(Node *head){
    Node* temp=head;
    while(temp!=NULL){
        cout << temp->data << "->";
        temp=temp->next;
    }
    cout << "NULL" << endl;
}

void insertAtTail(Node* &head, int value){
    if(head == NULL){
        Node* temp = new Node(value);
        head = temp;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    Node* temp2 = new Node(value);
    temp->next = temp2;
    temp2->prev = temp;
}

Node* flatten(Node* head) {
    // BASE CASE
    if(head==NULL)
        return head;

    Node* curr = head;
    while(curr!=NULL){
        if(curr->child!=NULL){
            Node* temp = curr->next;
            curr->next = flatten(curr->child);
            curr->child = NULL;
            curr->next->prev = curr;

            while(curr->next!=NULL)
                curr = curr->next;

            curr->next = temp;
            if(temp!=NULL)
               temp->prev = curr;
        }
        curr = curr->next;
    }

    return head;
}

int main()
{
    Node* head1 = NULL;
    insertAtTail(head1, 1);
    insertAtTail(head1, 2);
    insertAtTail(head1, 3);
    display(head1);

    Node* head2 = NULL;
    insertAtTail(head2, 4);
    insertAtTail(head2, 5);
    insertAtTail(head2, 6);
    display(head2);

    Node* head3 = NULL;
    insertAtTail(head3, 7);
    insertAtTail(head3, 8);
    insertAtTail(head3, 9);
    display(head3);

    Node* temp = head1;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->child = head3;

    temp = head1;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next = head2;
    head2->prev = temp;

    Node* head = flatten(head1);
    display(head);

    return 0;
}
