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

node* deleteDuplicates(node* head) {
    node* temp = head;
    while(temp!= NULL && temp->next != NULL){
        if(temp->data == temp->next->data){
            node* to_del = temp->next;
            temp->next = temp->next->next;
            delete to_del;
            continue;
        }
        temp=temp->next;
    }
    return head;
}

int main()
{
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 1);
    insertAtTail(head, 2);

    head = deleteDuplicates(head);
    node* temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}