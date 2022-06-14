// Multiply two numbers represented by Linked Lists
// Input : 9->4->6
//         8->4
// Output : 79464

// Input : 3->2->1
//         1->2
// Output : 3852

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

int func(node* &head1, node* &head2){
    int num1 = 0;
    int num2 = 0;
    node* temp = head1;

    while(temp!=NULL){
        num1= num1*10 + temp->data;
        temp=temp->next;
    }
    temp=head2;
    while(temp!=NULL){
        num2= num2*10 + temp->data;
        temp=temp->next;
    }
    return num1*num2;
}

int main()
{
    node* head1 = NULL;
    node* head2 = NULL;

    insertAtTail(head1, 3);
    insertAtTail(head1, 2);
    insertAtTail(head1, 1);

    insertAtTail(head2, 1);
    insertAtTail(head2, 2);

    cout << func(head1, head2);

    return 0;
}