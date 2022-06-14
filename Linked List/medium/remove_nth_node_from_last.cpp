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


void removeNthFromEnd(node* &head, int n) {
    int count=0;
    node* temp = head;
    while(temp!=NULL){
        temp = temp->next;
        count++;
    }

    int idx = count-n;      // this is the index of the element to be removed
    temp = head;
    count = 1;

    if(idx == 0){       // means delete at head
        temp = head;
        head = head->next;
        free(temp);
        return;
    }

    while(count != idx){
        temp=temp->next;
        count++;
    }

    node* to_delete = temp->next;
    temp->next = temp->next->next;
    free(to_delete);
    return;
}

int main()
{
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);

    removeNthFromEnd(head, 1);
    node* temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "NULL" << endl;


    return 0;
}