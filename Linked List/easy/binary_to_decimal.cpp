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

int Bin_To_Dec(node* head){
    int num=0;
    node* temp = head;
    while(temp!=NULL){
        num = num*10 + temp->data;
        temp = temp->next;
    }

    int n=0, ans=0;
    while(num>0){
        int x = num%10;
        ans = ans + x*pow(2, n);
        n++;
        num=num/10;
    }
    return ans;
}


int main()
{
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 0);
    insertAtTail(head, 1);
    insertAtTail(head, 1);

    cout << Bin_To_Dec(head);

    return 0;
}
