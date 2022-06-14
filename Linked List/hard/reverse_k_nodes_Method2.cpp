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


node* reverse_k_nodes(node* head, int k){
    node* prev = NULL;
    node* curr = head;
    node* next;

    int count=0;
    node* temp = head;
    // this loop ensures that all k elements that need to be reversed are present
    while(count < k){
        if(temp==NULL)
            return head;
        temp=temp->next;
        count++;
    }
    while(curr != NULL && count < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if(next!=NULL)
        head->next = reverse_k_nodes(next, k);
    return prev;
}

int main()
{
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    head = reverse_k_nodes(head, 3);

    node* temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}