#include<bits/stdc++.h>
using namespace std;

bool findRedundantBrackets(string &s)
{
    stack<int> st;
    for(int i=0; i<s.length(); i++){
        char ch = s[i];
        if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/')
            st.push(ch);

        else{
            if(ch==')'){
                bool isRedundant=true;      // we assumed this bracket is redundant agar koi operator mil gya hume top of stack mein then hum iski value false kr denege
                while(st.top() != '('){
                    char temp = st.top();
                    if(temp=='+' || temp=='-' || temp=='*' || temp=='/')
                        isRedundant = false;
                    st.pop();
                }
                st.pop();       // removing opening bracket
                if(isRedundant == true)
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    // string s = "5";
    // string s = "(a+(b*(a/c)))";
    // string s = "(a/c+(b))";
    string s = "(b/a)";
    // string s = "((b-c+a/c))";

    cout << findRedundantBrackets(s);

    return 0;
}