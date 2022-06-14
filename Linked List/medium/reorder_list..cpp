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

void insertAtTail(node* &my_ptr, int value){
    if(my_ptr == NULL){
        node* temp = new node(value);
        my_ptr = temp;
        return;
    }

    node* temp = my_ptr;
    while(temp->next != NULL)
        temp = temp->next;

    node* temp2 = new node(value);
    temp->next = temp2;
}

node* reorder_list(node* &head){
    node* curr = head;
    node* temp;
    node* ptr;

    while(curr->next != NULL && curr->next->next != NULL){
        temp = curr;
        while(temp->next->next != NULL)
            temp = temp->next;
        ptr = temp->next;
        temp->next = temp->next->next;
        ptr->next = curr->next;
        curr->next = ptr;
        curr = curr->next->next;
    }
    return head;
}

int main()
{
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);

    head = reorder_list(head);

    node* temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}