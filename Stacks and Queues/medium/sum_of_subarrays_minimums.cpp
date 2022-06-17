#include <bits/stdc++.h>
using namespace std;


// NAIVE APPROACH
vector<int> nextMinIndex(vector<int> arr){
    int n = arr.size();
    vector<int> result(n);
    stack<int> st;
    st.push(-1);
    for (int i = n - 1; i >= 0; i--){
        while (st.top() != -1 && arr[st.top()] >= arr[i])
            st.pop();
        result[i] = st.top();
        st.push(i);
    }
    for (int i = 0; i < n; i++){
        if (result[i] == -1)
            result[i] = n;
    }
    return result;
}

vector<int> prevMinIndex(vector<int> arr){
    int n = arr.size();
    vector<int> result(n);
    stack<int> st;
    st.push(-1);
    for (int i = 0; i < n; i++){
        while (st.top() != -1 && arr[st.top()] > arr[i])
            st.pop();
        result[i] = st.top();
        st.push(i);
    }

    for (int i = 0; i < n; i++){
        if (result[i] == -1)
            result[i] = -1;
    }
    return result;
}

int sumSubarrayMins(vector<int> &arr)
{
    int n = arr.size();

    vector<int> next(n);
    next = nextMinIndex(arr);

    vector<int> prev(n);
    prev = prevMinIndex(arr);

    for (int i = 0; i < n; i++)
        cout << next[i] << " ";
    cout << endl;

    for (int i = 0; i < n; i++)
        cout << prev[i] << " ";
    cout << endl;

    long long minSum = 0;
    for (int i = 0; i < n; i++){
        int g1 = i - prev[i];
        int g2 = next[i] - i;
        int temp = g1 * g2;
        minSum += temp * arr[i];
    }
    return minSum;
}

int main()
{

    return 0;
}