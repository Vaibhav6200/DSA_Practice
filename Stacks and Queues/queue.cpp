#include <bits/stdc++.h>
using namespace std;

class myQueue
{
public:
    int *arr;
    int n;
    int front;
    int back;

    myQueue(int size)
    {
        n = size;
        arr = new int[n];
        front = -1;
        back = -1;
    }

    void push(int val)
    {
        if(back == 0){
            cout << "Stack Overflow" << endl;
            return;
        }
        if (front == -1)
        {
            front = n - 1;
            back = n - 1;
            arr[back] = val;
            return;
        }
        arr[--back] = val;
    }

    int pop()
    {
        if (front == -1)
        {
            cout << "No element to pop" << endl;
            return -1;
        }
        if (front == back)
        {
            int temp = arr[back];
            front = back = -1;
            return temp;
        }
        int temp = arr[front--];
        return temp;
    }
};

int main()
{
    int n = 3;
    myQueue q(n);
    q.push(1);
    q.push(2);
    q.push(3);
    // q.push(3);

    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;

    return 0;
}