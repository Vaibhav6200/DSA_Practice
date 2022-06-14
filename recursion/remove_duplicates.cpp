#include<bits/stdc++.h>
using namespace std;

string remove(string str){

    if (str.length() == 0)
        return "";

    string rem_string = remove(str.substr(1));

    for(int i=0 ; i < rem_string.length() ; i++)
        if(str[0] == rem_string[i])
            return rem_string;

    return str[0] + rem_string;
}

int main()
{
    string str = "aaaabbbeeecdddd";
    cout << remove(str);
    return 0;
}