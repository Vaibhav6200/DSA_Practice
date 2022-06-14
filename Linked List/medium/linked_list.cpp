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

void insertAtTail(node* my_ptr, int value){
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


int main()
{
    node* head = NULL;

    node* temp = new node(1);
    head = temp;

    node* temp2 = new node(2);
    temp->next = temp2;

    temp = new node(3);
    temp2->next = temp;

//  head->[1]->[2]->[3]->NULL
    cout << "Before Insertion: ";
    temp = head;
    while(temp->next != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << temp->data << endl;

    insertAtTail(head, 4);

    cout << "After Insertion: ";
    temp = head;
    while(temp->next != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << temp->data << endl;

    return 0;
}