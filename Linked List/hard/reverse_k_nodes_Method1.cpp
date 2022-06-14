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


node* reverse(node* head, node* tail){
    if(head==tail || head->next==tail)
        return head;

    node* newhead = reverse(head->next, tail);
    head->next->next = head;
    head->next = NULL;

    return newhead;
}

node* reverse_k_nodes(node* head, int k){
    int count = 1;
    node* temp = head;
    while(count != k){
        temp = temp->next;
        count++;
        if(temp == NULL)
            return head;
    }
    node* ptr = reverse_k_nodes(temp->next, k);
    node* newhead = reverse(head, temp->next);
    head->next = ptr;
    return newhead;
}

int main()
{
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    head = reverse_k_nodes(head, 2);

    node* temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}