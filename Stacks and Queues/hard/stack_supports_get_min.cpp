#include<bits/stdc++.h>
using namespace std;


class SpecialStack {
    public:
    stack<int> st;
    int mini;
    void push(int data) {
        if(st.empty()){
            st.push(data);
            mini = data;
        }
        else{
            if(data < mini){
                int val = 2*data - mini;
                st.push(val);
                mini = min(mini, data);
            }
            else
                st.push(data);
        }
    }

    int pop() {
        if(st.empty())
            return -1;

        int curr = st.top();
        st.pop();
        if(curr>mini){
            return curr;
        }
        else{
            int temp = mini;
            int val = 2*mini - curr;
            mini = val;
            return temp;
        }
    }

    int top() {
        int curr = st.top();
        if(st.empty())
            return -1;
        if(curr<mini)
            return mini;
        else
            return curr;
    }

    bool isEmpty() {
        return st.empty();
    }

    int getMin() {
        if(st.empty())
            return -1;
        return mini;
    }
};

int main()
{

    return 0;
}