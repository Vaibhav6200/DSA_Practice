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


bool detect_cycle(node* head){
    node* ptr1=head;
    node* ptr2=head;

    do{
        if(ptr2->next == NULL || ptr2->next->next == NULL)
            return false;
        ptr1=ptr1->next;
        ptr2=ptr2->next->next;
    }while(ptr1 != ptr2);

    return true;
}


void remove_cycle(node* head){
    node* ptr1=head;
    node* ptr2=head;

    do{
        ptr1=ptr1->next;
        ptr2=ptr2->next->next;
    }while(ptr1 != ptr2);

    // Taking our 1 pointer back to head
    ptr1 = head;

    while(ptr1->next != ptr2->next){
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    ptr2->next = NULL;

}

int main()
{
    node* head = NULL;


    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    insertAtTail(head, 8);
    insertAtTail(head, 9);

    node* temp = head;
    node* temp2;
    while(temp->next != NULL){
        if(temp->data == 4)
            temp2 = temp;
        temp = temp->next;
    }
    temp->next = temp2;     // making cycle

    cout << detect_cycle(head) << endl;
    remove_cycle(head);
    cout << detect_cycle(head);

    return 0;
}