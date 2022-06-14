#include<bits/stdc++.h>
using namespace std;


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
    return result;
}

int main()
{
    int arr[] = {10, 20, 30, 50, 10, 70, 30};
    int n=7;
    vector<int> result(n);
    result = prevMinIndex(arr, n);
    for(int i=0; i<n; i++)
        cout << result[i] << " ";
    cout << endl;

    return 0;
}