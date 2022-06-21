#include<bits/stdc++.h>
using namespace std;

class kQueue{
    int *arr;
    int *next;
    int *front;
    int *rear;
    int freespot;
public:
    kQueue(int S, int K){
        // Declarations
        arr = new int[S];
        next = new int[S];
        front = new int[K];
        rear = new int[K];

        // Initializing next array
        for(int i=0; i<S-1; i++)
            next[i]=i+1;
        next[S-1] = -1;

        // Initializing front and rear arrays
        for(int i=0; i<K; i++){
            front[i] = -1;
            rear[i] = -1;
        }

        // Initializing freespot
        freespot = 0;
    }

    bool push(int value, int m){
        // OVERFLOW CONDITION CHECK
        if(freespot == -1)
            return false;

        // Step 1: fetch free index
        int index = freespot;

        // Step 2: Update freespot
        freespot = next[index];

        // Step 3: Update front and rear pointers
        if(front[m-1] == -1)        // check whether first element
            front[m-1] = index;     // m-1 is due to zero based indexing
        else
            next[rear[m-1]] = index;    // link new element with the previous element


        next[index] = -1;   // useful when we have to pop last element, we do front[m-1] = next[index]  if we have last element then next[index] will point to -1

        // Step 4: Update rear
        rear[m-1] = index;

        // Step 5: Insert Value in queue
        arr[index] = value;

        return true;
    }

    int pop(int m){
        // Step 1: Check Underflow condition
        if(front[m-1] == -1)
            return -1;

        // Step 2: Move Front pointer forward
        int index = front[m-1];     // this is the index of the element that is to be popped
        front[m-1] = next[index];   // Move front to next element

        // Managing freespot
        next[index] = freespot;
        freespot = index;

        return arr[index];      // returning value that is to be popped
    }
};

int main()
{
    kQueue q(10, 3);
    q.push(10, 1);
    q.push(15, 1);
    q.push(20, 2);
    q.push(25, 1);

    cout << q.pop(1) << endl;
    cout << q.pop(2) << endl;
    cout << q.pop(1) << endl;
    cout << q.pop(1) << endl;
    return 0;
}