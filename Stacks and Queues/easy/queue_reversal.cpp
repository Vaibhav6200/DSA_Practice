#include<bits/stdc++.h>
using namespace std;

// METHOD 1: Using Stack
queue<int> rev(queue<int> q){
    stack<int> st;
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    return q;
}


// METHOD 2: Using Recursion
// queue<int> rev(queue<int> q)
// {
//     if(q.empty())
//         return q;
//     int temp = q.front();
//     q.pop();
//     q = rev(q);
//     q.push(temp);
//     return q;
// }

int main()
{
    queue<int> q;
    q.push(4);
    q.push(3);
    q.push(1);
    q.push(10);
    q.push(2);
    q.push(6);

    // while(!q.empty()){
    //     cout << q.front() << " ";
    //     q.pop();
    // }
    // cout << endl;

    queue<int> result = rev(q);

    while(!result.empty()){
        cout << result.front() << " ";
        result.pop();
    }

    return 0;
}