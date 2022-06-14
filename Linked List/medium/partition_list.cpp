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

void display(node *head){
    node* temp=head;
    while(temp!=NULL){
        cout << temp->data << "->";
        temp=temp->next;
    }
    cout << "NULL" << endl;
}

void swap(int* i, int *j){
    int temp=*i;
    *i=*j;
    *j=temp;
}

node* partition_list(node* &head, int pivot){
    if(head == NULL)
        return head;
    node* temp=NULL;
    node* less=NULL;
    node* greater=NULL;

//         Setting Less and greater pointers
    temp=head;
    while(temp!=NULL){
        if(temp->data<pivot){
            less=temp;
            break;
        }
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        if(temp->data>=pivot){
            greater=temp;
            break;
        }
        temp=temp->next;
    }

//        Changing links for less and greater lists;
    node* ptr1 = less;
    node* ptr2 = greater;
    temp=head;
    while(temp!=NULL){
        if(temp==less || temp==greater){
            temp=temp->next;
            continue;
        }
        if(temp->data < pivot){
            ptr1->next = temp;
            ptr1 = ptr1->next;
        }
        else{
            ptr2->next = temp;
            ptr2 = ptr2->next;
        }
        temp = temp->next;
    }
    if(less == NULL)
        return greater;
    ptr1->next = greater;
    if(greater !=NULL)
        ptr2->next = NULL;
    return less;
}


int main()
{
    node* head = NULL;
    insertAtTail(head, 1);
    // insertAtTail(head, 4);
    // insertAtTail(head, 3);
    // insertAtTail(head, 2);
    // insertAtTail(head, 5);
    // insertAtTail(head, 2);
    display(head);

    int val=0;
    head = partition_list(head, val);
    display(head);

    return 0;
}