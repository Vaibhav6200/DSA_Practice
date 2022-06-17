#include<bits/stdc++.h>
using namespace std;

class MyCircularQueue {
public:
    int * arr;
    int size;
    int front;
    int rear;
    MyCircularQueue(int k) {
        front = rear = -1;
        size = k;
        arr = new int[size];
    }

    bool push_front(int value) {
        if(isEmpty()){
            front=rear=0;
            arr[rear] = value;
            return true;
        }
        if(isFull())
            return false;

        if(front == 0)      // making queue circular
            front = size-1;
        else
            front--;
        arr[front] = value;
        return true;
    }

    bool push_rear(int value) {
        if(isEmpty()){
            front = rear = 0;
            arr[front] = value;
            return true;
        }
        if(isFull())
            return false;
        rear = (rear+1)%size;
        arr[rear] = value;
        return true;
    }

    bool pop_front() {
        if(isEmpty())
            return false;
        if(front==rear){    // means we are popping last element
            front = rear = -1;
            return true;
        }
        front = (front+1)%size;
        return true;
    }

    bool pop_rear() {
        if(isEmpty())
            return false;
        if(front==rear){    // means we are popping last element
            front = rear = -1;
            return true;
        }
        if(rear==0)
            rear=size-1;
        else
            rear--;
        return true;
    }

    int Front() {
        if(isEmpty())
            return -1;
        return arr[front];
    }

    int Rear() {
        if(isEmpty())
            return -1;
        return arr[rear];
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear+1)%size == front;
    }
};


int main()
{
    MyCircularQueue q(7);
    q.push_front(3);
    q.push_front(4);

    return 0;
}