#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElementIndex(vector<int> arr)
{
    int n = arr.size();
    vector<int> result(n);

    int infinity = INT_MAX;
    stack<int> st;
    st.push(infinity);

    for (int i = n - 1; i >= 0; i--){
        while (st.top()!=infinity && arr[st.top()] < arr[i])
            st.pop();
        result[i] = st.top();
        st.push(i);
    }

    for (int i = 0; i < n; i++){
        if (result[i] == infinity)
            result[i] = 0;
    }

    return result;
}

int main()
{

    return 0;
}