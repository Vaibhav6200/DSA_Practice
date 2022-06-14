#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
    int top;
    int size;
    int* arr;
    Stack(int n){
        top = -1;
        size = n;
        arr = new int[n];
    }

    // PUSH
    void push(int val){
        if(top < size-1)
            arr[++top] = val;
        else
            cout << "Stack Overflow" << endl;
    }

    // POP
    void pop(){
        if(top!=-1)
            top--;
        else
            cout << "No Element to pop" << endl;
    }

    // PEEK
    int peek(){
        if(top!=-1)
            return arr[top];
        else{
            cout << "No Element to Peek" << endl;
            return -1;
        }
    }

    // IS EMPTY
    bool empty(){
        return top==-1;
    }

};


int main()
{
    Stack st(3);
    st.push(6);
    st.push(5);
    st.push(9);
    cout << st.peek() << endl;;
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    cout << st.peek() << endl;;
    return 0;
}