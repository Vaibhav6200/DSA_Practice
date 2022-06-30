#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    int val=0;
    ListNode* next;
    ListNode(int data){
        val = data;
        next=NULL;
    }
};


class Node{
    public:
    ListNode* head; // head in vector of list
    int i;      // Index of that Head

    Node(ListNode* tmp, int index){
        head = tmp;
        i = index;
    }
};

class compare{
    public:
    bool operator()(Node* a, Node* b){
        return a->head->val >= b->head->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    // Step1: Insert First K heads in our Min Heap
    int k = lists.size();
    for(int i=0; i<k; i++){
        if(lists[i] != NULL){
            Node* temp = new Node(lists[i], i);
            minHeap.push(temp);
        }
    }

    ListNode* head = NULL;
    ListNode* tail = NULL;
    while(!minHeap.empty())
    {
        Node* node = minHeap.top(); minHeap.pop();

        ListNode* temp = node->head;
        int index = node->i;

        if(temp!= NULL && temp->next != NULL)
        {
            lists[index] = lists[index]->next;
            Node* n = new Node(lists[index], index);
            minHeap.push(n);
        }

        if(head == NULL)
            head = tail = temp;
        else{
            if(temp!= NULL){
                tail->next = temp;
                tail = tail->next;
            }
        }
    }
    return head;
}