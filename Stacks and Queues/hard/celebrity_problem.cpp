// Note: Celebrity Knows no one
// All people knows celebrity


#include<bits/stdc++.h>
using namespace std;

bool knows(vector<vector<int>> arr, int a, int b){
    int n = arr.size();
    if(arr[a][b] == 1)
        return true;
    return false;
}

int find_celebrity(vector<vector<int>> arr){
    // Step1: push all persons in stack
    int n = arr.size();
    stack<int> st;
    for(int i=0; i<n; i++)
        st.push(i);

    // Step2: while there is onely 1 element in stack, pop 2 persons and check condition for celebrity
    while(st.size()>1){
        int a = st.top();
        st.pop();

        int b = st.top();
        st.pop();

        if(knows(arr, a, b))     // check if a knows b
            st.push(b);
        else
            st.push(a);
    }
    int celebrity = st.top();

    // Step3: Verify that the element present is stack is actually a celebrity or not.
    // NOTE: celebrity has all elements in its row=0 and all column elements = 1
    // Row Check
    bool rowFlag = false;
    int count=0;
    for(int i=0;i<n; i++){
        if(arr[celebrity][i] == 0)
            count++;
    }
    if(count == n)
        rowFlag = true;


    // Col Check
    bool colFlag = false;
    count=0;
    for(int i=0;i<n; i++){
        if(arr[i][celebrity] == 1)
            count++;
    }
    if(count == n-1)
        colFlag=true;

    if(rowFlag && colFlag)
        return celebrity;
    return -1;
}

int main()
{

    return 0;
}