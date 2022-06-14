// Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only.
// The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to head side,
// 2s at the end of the linked list, and 1s in the mid of 0s and 2s.

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

node* sort(node* head){
    int count[3] = {0};
    node* temp = head;
    while(temp!=NULL){
        count[temp->data]++;
        temp = temp->next;
    }

    int i=0;
    temp=head;
    while(temp!=NULL){
        if(count[i]==0)
            i++;
        else{
            temp->data = i;
            count[i]--;
            temp = temp->next;
        }
    }
    return head;
}

int main()
{
    node* head = NULL;

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 2);
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 0);
    insertAtTail(head, 2);
    insertAtTail(head, 2);

    head = sort(head);

    node* temp = head;
    while(temp!= NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}