#include<bits/stdc++.h>
using namespace std;

void recursive_mid_remove(stack<int> &st, int count, int size){
    if(count == size/2){
        st.pop();
        return;
    }

    int top = st.top();
    st.pop();

    recursive_mid_remove(st, count+1, size);

    st.push(top);
}

int main()
{
    stack<int> st;
    st.push(5);
    st.push(9);
    st.push(8);
    st.push(4);

    recursive_mid_remove(st, 0, 5);

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}