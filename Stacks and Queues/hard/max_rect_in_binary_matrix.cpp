#include<bits/stdc++.h>
using namespace std;

vector<int> next_min_element_index(vector<int> arr, int n){
    stack<int> st;
    st.push(-1);
    vector<int> next(n);

    for(int i=n-1; i>=0; i--){
        while(st.top()!=-1 && arr[st.top()] >= arr[i])
            st.pop();
        next[i] = st.top();
        st.push(i);
    }
    return next;
}

vector<int> prev_min_element_index(vector<int> &arr, int n){
    stack<int> st;
    st.push(-1);
    vector<int> prev(n);

    for(int i=0; i<n; i++){
        while(st.top()!=-1 && arr[st.top()] >= arr[i])
            st.pop();
        prev[i] = st.top();
        st.push(i);
    }
    return prev;
}

int find_max_rect_area(vector<int> arr, int n){
    int area = INT_MIN;

    vector<int> next(n);
    next = next_min_element_index(arr, n);

    vector<int> prev(n);
    prev = prev_min_element_index(arr, n);

    for(int i=0; i<n; i++){
        int l = arr[i];     // length of the rectangle
        if(next[i]==-1)
            next[i] = n;
        int b = next[i] - prev[i] - 1;
        int newArea = l*b;
        area = max(area, newArea);
    }
    return area;
}

int maximalRectangle(vector<vector<int>> matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    vector<int> arr(col);

    for(int j=0; j<col ; j++){
        int count=0;
        for(int i=0; i<row; i++){
            if(matrix[i][j] == 1)
                count++;
        }
        arr[j] = count;
    }

    int area = find_max_rect_area(arr, col);
    return area;
}

int main()
{
    int row=4;
    int col=5;

    vector<vector<int>> matrix;
    vector<int> v;
    // v = {1, 0, 1, 0, 0};
    // matrix.push_back(v);
    // v = {1, 0, 1, 1, 1};
    // matrix.push_back(v);
    // v = {1, 1, 1, 1, 1};
    // matrix.push_back(v);
    // v = {1, 0, 0, 1, 0};
    // matrix.push_back(v);

    v = {1, 1, 1, 1, 0};
    matrix.push_back(v);
    v = {1, 1, 1, 1, 1};
    matrix.push_back(v);
    v = {1, 1, 1, 1, 1};
    matrix.push_back(v);
    v = {1, 1, 1, 1, 1};
    matrix.push_back(v);

// printing our input matrix
    cout << endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    cout << endl;

// Finding Maximal Rectangle
    int area= maximalRectangle(matrix);
    cout << area << endl;

    return 0;
}