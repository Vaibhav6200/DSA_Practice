// Given the head of a singly linked list and two integers left and right where left <= right,
// reverse the nodes of the list from position left to position right, and return the reversed list.

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

    if(head == tail || head->next==tail)
        return head;

    node* newhead = reverse(head->next, tail);
    head->next->next = head;
    head->next = NULL;

    return newhead;
}

void reverse_given_part(node* &head, node* left, node* right){
    if(left==right)
        return;

    node* temp1=head;
    node* temp2=right->next;

    // Base Case
    if(head == left){
        node* newhead = reverse(head, right->next);
        head->next = temp2;
        head = newhead;
    }
    else{
        while(temp1->next != left)
            temp1 = temp1->next;

        node* newhead = reverse(left, right->next);
        // moving tail to the end of the reversed list
        node* tail=newhead;
        while(tail->next!=NULL)
            tail = tail->next;

        temp1->next = newhead;
        tail->next = temp2;
    }
}

int main()
{
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);

    node* left = head;
    node* right = head;

    while(left->data != 2)
        left = left->next;

    while(right->data != 4)
        right = right->next;

    reverse_given_part(head, left, right);

    node* temp=head;
    while(temp!=NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout <<"NULL" << endl;

    return 0;
}