#include <bits/stdc++.h>
using namespace std;

bool ispar(string x)
{
    stack<int> st;
    for (int i = 0; i < x.length(); i++)
    {
        char ch = x[i];
        if (ch == '(' || ch == '{' || ch == '[')
            st.push(ch);
        else if (!st.empty())
        {
            if ((st.top() == '(' && ch != ')') || (st.top() != '{' && ch == '}') || (st.top() == '[' && ch != ']'))
                return false;
            st.pop();
        }
        else
            return false;
    }
    if (!st.empty())
        return false;
    return true;
}

int main()
{

    return 0;
}