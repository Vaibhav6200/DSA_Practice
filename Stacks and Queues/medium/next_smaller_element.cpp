#include<bits/stdc++.h>
#include<vector>
using namespace std;

// int find_min(stack<int> st, int val){
//     if(st.empty())
//         return -1;

//     int top = st.top();
//     if(top<val)
//         return top;
//     st.pop();
//     return find_min(st, val);
// }

vector<int> next_min_element(vector<int> arr, int n) {
    stack<int> st;
    st.push(-1);
    int result[n];
    for(int i=n-1; i>=0; i--){
        while(st.top()>=arr[i])
            st.pop();
        result[i] = st.top();
        st.push(arr[i]);
    }

    vector<int> res;
    for(int i=0 ; i<n; i++)
        res.push_back(result[i]);

    return res;
}


int main()
{
    vector<int> arr;
    // [1, 5, 3, 2, 4]
    // 2 5 3 7 1 5 2 6 3 1
    arr.push_back(2);
    arr.push_back(5);
    arr.push_back(3);
    arr.push_back(7);
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(2);
    arr.push_back(6);
    arr.push_back(3);
    arr.push_back(1);
    int n=10;
    arr = next_min_element(arr, n);
    for(int i=0; i<arr.size(); i++)
        cout << arr[i] << " ";

    return 0;
}