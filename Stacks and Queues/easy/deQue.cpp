#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class deQue{
    public:
    node* head;
    node* tail;

    deQue(){
        head = tail = NULL;
    }

    // PUSH IS DONE THROUGH HEAD
    void insert_first(int val){
        node* temp = new node(val);
        if(head == NULL){
            head = tail = temp;
            return;
        }
        temp->next = head;
        head->prev = temp;
        head = head->prev;
    }

    // PUSH IS DONE THROUGH TAIL
    void insert_last(int val){
        node* temp = new node(val);
        if(head == NULL){
            head = tail = temp;
            return;
        }
        temp->prev = tail;
        tail->next = temp;
        tail = tail->next;
    }

    // POP IS DONE THROUGH HEAD
    int remove_first(){
        if(head == NULL)
            return -1;

        node* to_del = head;
        if(head == tail){
            int x = head->data;
            head = tail = NULL;
            delete to_del;
            return x;
        }

        int x = head->data;
        head = head->next;
        head->prev = NULL;
        delete to_del;
        return x;
    }

    // POP IS DONE THROUGH TAIL
    int remove_last(){
        if(head == NULL)
            return -1;

        node* to_del = tail;
        if(head == tail){
            int x = head->data;
            head = tail = NULL;
            delete to_del;
            return x;
        }

        int x = tail->data;
        tail = tail->prev;
        tail->next = NULL;
        delete to_del;
        return x;
    }
};


class Stack: public deQue{
    public:
    void push(int val){
        insert_last(val);
    }
    void pop(int val){
        remove_last();
    }
};

class Queue: public deQue{
    public:
    void push(int val){
        insert_last(val);
    }
    void pop(int val){
        remove_first();
    }
};


int main()
{
    deQue q;

    return 0;
}