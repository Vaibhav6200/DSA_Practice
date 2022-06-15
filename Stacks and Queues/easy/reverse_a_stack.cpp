#include<bits/stdc++.h>
using namespace std;


void push_at_bottom(stack<int> &st, int val){
    // Base case
    if(st.empty()){
        st.push(val);
        return;
    }

    int top = st.top();
    st.pop();

    // Recursive call
    push_at_bottom(st, val);
    st.push(top);
}

void reverse_stack(stack<int> &st){
    if(st.empty())
        return;

    int top = st.top();
    st.pop();

    reverse_stack(st);
    push_at_bottom(st, top);
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);

    reverse_stack(st);
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}