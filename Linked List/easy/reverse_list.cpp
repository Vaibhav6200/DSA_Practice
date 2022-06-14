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

void reverse(node* &head){
    node* ptr1 = NULL;
    node* ptr2 = head;
    node* ptr3 = ptr2;

    while(ptr2!=NULL){
        ptr3 = ptr3->next;
        ptr2->next = ptr1;
        ptr1=ptr2;
        ptr2=ptr3;
    }
    head = ptr1;
}

node* recursive_reverse(node* &head, node* &prev){
    if(head==NULL)
        return prev;

    node* temp = head->next;
    head->next = prev;
    prev = head;
    return recursive_reverse(temp, prev);
}

node* RecursiveReverse2(node* &head){
    if(head==NULL || head->next==NULL)
        return head;

    node* newhead = RecursiveReverse2(head->next);
    head->next->next = head;
    head->next = NULL;

    return newhead;
}


int main()
{
    node* head = NULL;


    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);

    cout << "Before Reverse: ";
    node* temp = head;
    while(temp->next != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << temp->data << endl;

    // reverse(head);
    // node* prev = NULL;
    // head = recursive_reverse(head, prev);
    head = RecursiveReverse2(head);

    cout << "After Reverse: ";
    temp = head;
    while(temp->next != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << temp->data << endl;

    return 0;
}