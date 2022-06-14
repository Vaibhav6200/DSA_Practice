#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
    list<int> list;

    void push(int val){
        list.push_back(val);
    }

    void pop(){
        if(list.empty())
            cout <<"No Element to pop" << endl;
        else
            list.pop_back();
    }

    int peek(){
        if(list.empty())
            cout <<"No Element to peek" << endl;
        return list.back();
    }

    bool empty(){
        return list.empty();
    }
};

int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    st.pop();
    st.pop();
    st.pop();
    cout << st.peek() << endl;

    return 0;
}