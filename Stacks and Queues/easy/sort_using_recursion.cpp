#include<bits/stdc++.h>
using namespace std;

// Places an element in an sorted stack at its correct position
void place_element(stack<int> &st, int val){
    // Base Case
    if(st.empty() || (!st.empty() && val>st.top())){
        st.push(val);
        return;
    }

    // Recursive Call
    int temp = st.top();
    st.pop();
    place_element(st, val);
    st.push(temp);
}

void recursiveSort(stack<int> &st){
    if(st.empty())
        return;

    // Taking top element: We will sort it manually, rest stack will be solved using recursion
    int temp = st.top();
    st.pop();
    recursiveSort(st);

    // Placing top element at its correct position
    place_element(st, temp);
}

int main()
{
    stack<int> st;
    st.push(5);
    st.push(-2);
    st.push(9);
    st.push(-7);
    st.push(3);

    recursiveSort(st);
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}