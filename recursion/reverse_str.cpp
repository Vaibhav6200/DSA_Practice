// reverse a string using recursion

#include<bits/stdc++.h>
using namespace std;

string reverse(string str){
    if(str.length()==0)
        return "";
    return reverse(str.substr(1)) + str[0];
}

int main()
{
    string str = "Vaibhav";
    cout << reverse(str);
    return 0;
}