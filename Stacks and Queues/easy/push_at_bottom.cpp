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

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    push_at_bottom(st, 4);

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}