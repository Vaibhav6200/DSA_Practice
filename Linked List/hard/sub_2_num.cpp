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

void display(node *head){
    node* temp=head;
    while(temp!=NULL){
        cout << temp->data << "->";
        temp=temp->next;
    }
    cout << "NULL" << endl;
}

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

node* reverse_list(node* head){
    if(head->next == NULL)
        return head;
    node* temp = head;
    node* newHead = reverse_list(head->next);
    temp->next->next = temp;
    temp->next=NULL;
    return newHead;
}

int length(node* head){
    node* temp=head;
    int count=0;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    return count;
}

node* remove_start_zeroes(node* head){
    while(head->data == 0 && head!=NULL){
        node* to_delete=head;
        head = head->next;
        delete to_delete;
    }
    if(head==NULL)
        return NULL;
    return head;
}

node* subLinkedList(node* head1, node* head2){
    head1 = reverse_list(head1);
    head2 = reverse_list(head2);

    int len1 = length(head1);
    int len2 = length(head2);

    node* x;
    node* y;

    if(len1>=len2){
        x = head1;
        y = head2;
    }
    else{
        x = head2;
        y = head1;
    }

    node* head=NULL;
    int borrow=0;
    while(x!=NULL || y!=NULL){
        int num1 = x->data;
        int num2=0;
        if(y!=NULL)
            num2 = y->data;
        int num;
        if(borrow==1){
            num1--;
            borrow=0;
        }
        if(num1>=num2){
            num = num1-num2;
            insertAtTail(head, num);
        }
        else{
            borrow=1;
            num1 = num1+10;
            num = num1-num2;
            insertAtTail(head, num);
        }
        x=x->next;
        if(y!=NULL)
            y=y->next;
    }


    head = reverse_list(head);
    head = remove_start_zeroes(head);
    return head;
}

int main()
{
    node* head1 = NULL;
    insertAtTail(head1, 0);
    insertAtTail(head1, 7);
    insertAtTail(head1, 1);
    insertAtTail(head1, 5);
    display(head1);

    node* head2 = NULL;
    insertAtTail(head2, 0);
    insertAtTail(head2, 7);
    insertAtTail(head2, 1);
    insertAtTail(head2, 5);

    display(head2);

    node* head = NULL;
    head = subLinkedList(head1, head2);
    display(head);

// Example 1:
// 0 0 0 8
// 6 7 0 2 7 8 3 1 1 5 8 8 2 1 2 2

// Example 2:
// 0 7 1 5 3 6 1 0 7
// 0 7 1 5 3 6 1 0 7

    return 0;
}