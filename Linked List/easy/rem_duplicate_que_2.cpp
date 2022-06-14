// Given the head of a sorted linked list, delete all nodes that have duplicate numbers,
// leaving only distinct numbers from the original list. Return the linked list sorted as well.

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

void deleteList(node* &head){
    node* current = head;
    node* next = NULL;

    while (current != NULL){
        next = current->next;
        delete current;
        current = next;
    }
}

node* removeDuplicate(node* head) {
    node* temp = head;
    node* prev = head;
    node* to_delete;

    while(temp!=NULL && temp->next!=NULL){
        if(temp->data == temp->next->data){
            to_delete = temp;
            int val=temp->data;

            while(temp->data == val && temp!=NULL)
                temp=temp->next;

            if(prev == head){       // handling corner case e.g. [1->1->1->2->3]
                prev=temp;
                head=temp;
            }
            else{
                prev->next = temp;
                deleteList(to_delete);
            }
        }
        else{
            prev=temp;
            temp=temp->next;
        }
    }
    return head;
}

int main()
{
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 1);
    insertAtTail(head, 1);
    insertAtTail(head, 2);

    head = removeDuplicate(head);

    node* temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}