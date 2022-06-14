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

node* removeHead(node* head, int val){
    if(head->data == val){
        node* to_delete = head;
        head = head->next;
        delete to_delete;
    }
    return head;
}

node* removeElements(node* head, int val) {
    node* to_delete;
    node* temp = head;

    if(head==NULL)
        return head;

    while(temp!=NULL && temp->next!=NULL){
        if(temp->data == val){
            temp = removeHead(temp, val);
            head = temp;
            continue;
        }

        if(temp->next->data == val){
            to_delete = temp->next;
            temp->next = temp->next->next;
            delete to_delete;
            continue;
        }

        temp = temp->next;
    }

    if(temp->data == val)
        head = removeHead(temp, val);

    return head;
}
int main()
{
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 1);
    insertAtTail(head, 1);

    node* temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    int k=1;
    head = removeElements(head, k);

    temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}