#include<bits/stdc++.h>
using namespace std;


vector<int> nextSmallerElement(vector<int> arr, int n) {
    stack<int> st;
    st.push(-1);
    vector<int> result(n);
    for(int i=n-1; i>=0; i--){
        while(st.top()!=-1 && arr[st.top()]>=arr[i])
            st.pop();
        result[i] = st.top();
        st.push(i);
    }
    return result;
}

vector<int> prevSmallerElement(vector<int> arr, int n) {
    stack<int> st;
    st.push(-1);
    vector<int> result(n);

    for(int i=0; i<n; i++){
        while(st.top()!=-1 && arr[st.top()]>=arr[i])
            st.pop();
        result[i] = st.top();
        st.push(i);
    }
    return result;
}

int largestRectangleArea(vector<int> &heights){
    int n=heights.size();
    int area = INT_MIN;

    vector<int> next(n);
    next = nextSmallerElement(heights, n);

    vector<int> prev(n);
    prev = prevSmallerElement(heights, n);

    for(int i=0; i<n; i++){
        int l=heights[i];

        if(next[i] == -1)
            next[i] = n;
        int b = next[i] - prev[i] - 1;
        int newArea = l*b;

        area = max(newArea, area);
    }
    return area;
}

int main()
{
    vector<int> arr;
    // [1, 5, 3, 2, 4]
    // 2 5 3 7 1 5 2 6 3 1
    arr.push_back(4);
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(2);
    int n=5;

    cout << largestRectangleArea(arr);
    // arr.push_back(2);
    // arr.push_back(5);
    // arr.push_back(3);
    // arr.push_back(7);
    // arr.push_back(1);
    // arr.push_back(5);
    // arr.push_back(2);
    // arr.push_back(6);
    // arr.push_back(3);
    // arr.push_back(1);
    // int n=10;


    return 0;
}