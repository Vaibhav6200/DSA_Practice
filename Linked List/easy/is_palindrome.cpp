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


bool check(string s){
    int n = s.length();
    for(int i=0; i<n/2; i++){
        if(s[i] != s[n-i-1])
            return false;
    }
    return true;
}

bool isPalindrome(node* head) {
    node* temp = head;
    string s="";
    while(temp!=NULL){
        s+=to_string(temp->data);
        temp = temp->next;
    }
    return check(s);
}

int main()
{
    // cout << check("12345") << " " << check("12321") << " " << check("1221");

    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);

    isPalindrome(head);


    // node* temp = head;
    // while(temp!=NULL){
    //     cout << temp->data << " ";
    //     temp = temp->next;
    // }
    // cout << "NULL" << endl;

    return 0;
}
