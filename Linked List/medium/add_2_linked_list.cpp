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

node* add_2_list(node* head1, node* head2){
    head1 = reverse_list(head1);
    head2 = reverse_list(head2);

    node* head = NULL;
    node* x=head1;
    node* y=head2;
    int carry=0;
    int num, rem;
    while(x!=NULL || y!=NULL || carry!=0){
        int num1=0, num2=0;
        if(x!=NULL)
            num1 = x->data;
        if(y!=NULL)
            num2 = y->data;
        num = num1 + num2 + carry;
        rem = num%10;
        carry=num/10;
        insertAtTail(head, rem);
        if(x!=NULL)
            x=x->next;
        if(y!=NULL)
            y=y->next;
    }

    return head;
}

int main()
{
    node* head1 = NULL;
    insertAtTail(head1, 9);
    insertAtTail(head1, 4);
    insertAtTail(head1, 2);

    node* head2 = NULL;
    insertAtTail(head2, 9);
    insertAtTail(head2, 4);
    insertAtTail(head2, 6);
    insertAtTail(head2, 5);

    node* head = add_2_list(head1, head2);
    display(head);

    return 0;
}