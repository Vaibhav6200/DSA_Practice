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

    bool enQueue(int value) {
        if(isEmpty()){
            front=rear=0;
            arr[rear] = value;
            return true;
        }
        if(isFull())
            return false;
        rear = (rear+1)%size;
        arr[rear] = value;
        return true;
    }

    bool deQueue() {
        if(isEmpty())
            return false;
        if(front==rear){    // means we are popping last element
            front = rear = -1;
            return true;
        }
        front = (front+1)%size;
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
    q.enQueue(3);
    // q.enQueue(4);
    // q.enQueue(8);
    cout << q.Front() << " " ;
    return 0;
}