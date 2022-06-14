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


node* middleNode(node* head) {
    node* fast = head->next;
    node* slow = head;
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

node* merge(node* head1, node* head2){
    node* dummyNode = new node(0);
    node* ptr3 = dummyNode;

    node* ptr1 = head1;
    node* ptr2 = head2;

    while(ptr1!=NULL && ptr2!=NULL){
         if(ptr1->data < ptr2->data){
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        else{
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }
    while(ptr1!=NULL){
        ptr3->next = ptr1;
        ptr1 = ptr1->next;
        ptr3 = ptr3->next;
    }
    while(ptr2!=NULL){
        ptr3->next = ptr2;
        ptr2 = ptr2->next;
        ptr3 = ptr3->next;
    }

    return dummyNode->next;
}


node* mergeSort(node* head){
    // base case: if we have single node return
    if(head==NULL || head->next == NULL)
        return head;

    // Find Middle Node
    node* mid = middleNode(head);

    // Split List Into Left and Right Section: then recursively sort left section and then right section
    node* left = head;
    node* right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    // At Last merge both sorted linked list
    head = merge(left, right);

    return head;
}


int main()
{
    node*head = NULL;
    insertAtTail(head, 6);
    insertAtTail(head, 5);
    insertAtTail(head, 12);
    insertAtTail(head, 10);
    insertAtTail(head, 9);
    insertAtTail(head, 1);

    head = mergeSort(head);

    node* temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}