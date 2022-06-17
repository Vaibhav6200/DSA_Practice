#include<bits/stdc++.h>
using namespace std;

vector<int> prevGreaterElementIndex(vector<int> arr)
{
    int n = arr.size();
    vector<int> result(n);

    int infinity = INT_MAX;
    stack<int> st;
    st.push(infinity);

    for (int i=0; i<n; i++){
        while (st.top()!=infinity && arr[st.top()] <= arr[i])
            st.pop();
        result[i] = st.top();
        st.push(i);
    }

    for (int i = 0; i < n; i++){
        if (result[i] == infinity)
            result[i] = -1;
    }

    return result;
}

vector<int> stockSpan(vector<int> arr){
    int n = arr.size();
    vector<int> result(n);

    vector<int> prev = prevGreaterElementIndex(arr);

    for(int i=0; i<n; i++){
        if(prev[i] == -1){
            result[i] = 1;
            continue;
        }
        result[i] = i - prev[i];
    }
    return result;
}

int main()
{
    vector<int> arr;
    arr.push_back(100);
    arr.push_back(80);
    arr.push_back(60);
    arr.push_back(70);
    arr.push_back(60);
    arr.push_back(75);
    arr.push_back(85);

    vector<int> result = prevGreaterElementIndex(arr);
    for(int i=0; i<result.size(); i++)
        cout << result[i] << " ";
    cout << endl;

    result = stockSpan(arr);
    for(int i=0; i<result.size(); i++)
        cout << result[i] << " ";

    return 0;
}