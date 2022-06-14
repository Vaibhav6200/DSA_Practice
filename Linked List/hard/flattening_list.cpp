// Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
// (i) a next pointer to the next node,
// (ii) a bottom pointer to a linked list where this node is head.
// Each of the sub-linked-list is in sorted order.
// Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order.
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

class node{
    public:
    int data=0;
    node* next;
    node* bottom;
    node(int value){
        data = value;
        next=NULL;
        bottom=NULL;
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

node* middlenode(node* head) {
    node* fast = head->next;
    node* slow = head;
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

node* merge(node* head1, node* head2){
    node* dummynode = new node(0);
    node* ptr3 = dummynode;

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

    return dummynode->next;
}

node* mergeSort(node* head){
    // base case: if we have single node return
    if(head==NULL || head->next == NULL)
        return head;

    // Find Middle node
    node* mid = middlenode(head);

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

void my_display(node * head){
    node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

node* bottom_to_next(node* root){
    node* temp = root;
    node* ptr;
    while(temp!=NULL){
        ptr = temp->bottom;
        temp->next = ptr;
        temp->bottom = NULL;
        temp=temp->next;
    }
    return root;
}

node* flatten(node *root)
{
    node* head = root;
    node* temp;
    node* ptr;
    while(head!=NULL){
        temp = head->bottom;
        while(temp->bottom != NULL)
            temp = temp->bottom;
        temp->bottom = head->next;
        ptr = head;
        head = head->next;
        ptr->next = NULL;
    }
    root = bottom_to_next(root);
    root = mergeSort(root);
    my_display(root);
    return root;
}


int main()
{

    return 0;
}