#include<bits/stdc++.h>
using namespace std;

vector<int> nextMinIndex(int arr[], int n){
    vector<int> result(n);
    stack<int> st;
    st.push(-1);
    for(int i=n-1; i>=0; i--){
        while(st.top()!=-1 && arr[st.top()] >= arr[i])
            st.pop();
        result[i] = st.top();
        st.push(i);
    }
    for(int i=0; i<n; i++){
        if(result[i] == -1)
            result[i] = -1;
    }
    return result;
}

vector<int> prevMinIndex(int arr[], int n){
    vector<int> result(n);
    stack<int> st;
    st.push(-1);
    for(int i=0; i<n; i++){
        while(st.top()!=-1 && arr[st.top()] >= arr[i])
            st.pop();
        result[i] = st.top();
        st.push(i);
    }
    for(int i=0; i<n; i++){
        if(result[i] == -1)
            result[i] = -1;
    }
    return result;
}


int main()
{
    // int arr[] = {10, 20, 30, 50, 10, 70, 30};
    int arr[] = {3, 1, 2, 4};
    int n=4;
    vector<int> result(n);
    result = nextMinIndex(arr, n);
    for(int i=0; i<n; i++)
        cout << result[i] << " ";
    cout << endl;

    result = prevMinIndex(arr, n);
    for(int i=0; i<n; i++)
        cout << result[i] << " ";
    cout << endl;

    return 0;
}