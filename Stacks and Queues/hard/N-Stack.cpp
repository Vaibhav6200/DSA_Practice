#include<bits/stdc++.h>
using namespace std;

class NStack{
public:
    // Initialize your data structure.
    int freespot;
    int *arr;
    int *next;
    int *top;
    NStack(int N, int S)
    {
        top = new int[N];
        arr = new int[S];
        next = new int[S];

//         Initializing freespot
        freespot=0;

//         Initializing top array
        for(int i=0; i<N; i++)
            top[i] = -1;

//         Initializing next array
        for(int i=0; i<S-1; i++)
            next[i] = i+1;
//         Initillizing last index of next array
        next[S-1] = -1;
    }

    // Pushes 'value' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int value, int m)
    {
//         Checking overflow condition
        if(freespot == -1)
            return false;

//         Step1: Find index
        int index = freespot;

//         Step2: update freespot
        freespot = next[index];

//         Step3: insert element in array
        arr[index] = value;

//         Step4: update next array
        next[index] = top[m-1];        // m-1 because top array is zero indexed

//         Step5: update top array
        top[m-1] = index;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if(top[m-1] == -1)
            return -1;

//         FOLLOW REVERSE STEPS OF PUSH OPERATION TO POP ANY ELEMENT FROM STACK
        int index = top[m-1];
        top[m-1] = next[index];
        int value = arr[index];
        next[index] = freespot;
        freespot = index;

        return value;
    }
};

int main()
{

    return 0;
}