// Given a Linked List of size N, where every Node represents a sub-linked-list and contains two pointers:
// (i) a next pointer to the next Node,
// (ii) a bottom pointer to a linked list where this Node is head.
// Each of the sub-linked-list is in sorted order.
// Flatten the Link List such that all the Nodes appear in a single level while maintaining the sorted order.
// Note: The flattened list will be printed using the bottom pointer instead of next pointer.

// 5 -> 10 -> 19 -> 28
// |     |     |     |
// 7     20    22   35
// |           |     |
// 8          50    40
// |                 |
// 30               45

// input 2
// 1
// 4
// 163 187 560 836

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data=0;
    Node* next;
    Node* bottom;
    Node(int value){
        data = value;
        next=NULL;
        bottom=NULL;
    }
};

void insertAtTail(Node* &head, int value){
    if(head == NULL){
        Node* temp = new Node(value);
        head = temp;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    Node* temp2 = new Node(value);
    temp->next = temp2;
}

void my_display(Node * head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* merge(Node* head1, Node* head2){
    Node* dummyNode = new Node(0);
    Node* ptr3 = dummyNode;

    Node* ptr1 = head1;
    Node* ptr2 = head2;

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
Node* bottom_to_next(Node* root){
    Node* temp = root;
    Node* ptr;
    while(temp!=NULL){
        ptr = temp->bottom;
        temp->next = ptr;
        temp->bottom = NULL;
        temp=temp->next;
    }
    return root;
}

Node* next_to_bottom(Node* root){
    Node* temp = root;
    Node* ptr;
    while(temp!=NULL){
        ptr = temp->next;
        temp->bottom = ptr;
        temp->next = NULL;
        temp=temp->bottom;
    }
    return root;
}

Node* recursive_flatten(Node *head)
{
    if(head->next == NULL)
        return head;
    head->next = recursive_flatten(head->next);
    Node* list1 = head;
    Node* list2 = head->next;
    head->next=NULL;

    list1 = bottom_to_next(list1);
    list2 = bottom_to_next(list2);
    head = merge(list1, list2);
    head = next_to_bottom(head);
    return head;
}


int main()
{

    return 0;
}