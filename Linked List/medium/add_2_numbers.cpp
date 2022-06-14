// [2,4,3]
// [5,6,4]

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


int reverse(int n){
    int num=0;
    while(n>0){
        num = num*10 + n%10;
        n=n/10;
    }
    return num;
}

node* addTwoNumbers(node* l1, node* l2) {
    int num1 = 0;
    int num2 = 0;
    node* temp = l1;
    while(temp!=NULL){
        num1= num1*10 + temp->data;
        temp=temp->next;
    }

    temp=l2;
    while(temp!=NULL){
        num2= num2*10 + temp->data;
        temp=temp->next;
    }

    cout << num1 << " " << num2 << endl;
    num1 = reverse(num1);
    num2 = reverse(num2);


    int mult1=0, mult2=0;
    temp = l1;
    while(temp->data==0 && temp!=NULL){
        mult1++;
        temp=temp->next;
    }
    temp = l2;
    while(temp->data==0 && temp!=NULL){
        mult2++;
        temp=temp->next;
    }


    cout << "\nBefore Multiplication \n";
    cout << num1 << " " << num2 << endl;
    if(mult1)
        num1=num1*pow(10, mult1);
    if(mult2)
        num2=num2*pow(10, mult2);
    cout << "After Multiplication \n";
    cout << num1 << " " << num2 << endl << endl;

    cout << "Mult1: " << mult1 << " Mult2: " << mult2 << endl;
    int num = num1+num2;

    cout << num << endl;

    node* head=NULL;

    if(num==0)
        return new node(0);

    while(num>0){
        int x = num%10;
        insertAtTail(head, x);
        num/=10;
    }
    return head;
}

int main()
{
    node* head1 = NULL;

    insertAtTail(head1, 0);
    insertAtTail(head1, 0);
    insertAtTail(head1, 1);
    insertAtTail(head1, 4);
    insertAtTail(head1, 4);
    insertAtTail(head1, 3);
    insertAtTail(head1, 5);
    insertAtTail(head1, 9);
    insertAtTail(head1, 5);


    node* head2 = NULL;
    insertAtTail(head2, 9);
    insertAtTail(head2, 4);
    insertAtTail(head2, 0);
    insertAtTail(head2, 6);
    insertAtTail(head2, 1);
    insertAtTail(head2, 7);
    insertAtTail(head2, 8);
    insertAtTail(head2, 2);
    insertAtTail(head2, 1);
    insertAtTail(head2, 1);

    node*temp = head1;
    while(temp!=NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }cout << "NULL" << endl;

    temp = head2;
    while(temp!=NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }cout << "NULL" << endl;

    node* head = addTwoNumbers(head1, head2);
    temp=head;
    while(temp!=NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;


    return 0;
}