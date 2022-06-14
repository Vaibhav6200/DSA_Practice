// Move all x to the end of the string

#include<bits/stdc++.h>
using namespace std;

string move(string str){
    // Base Case
    if(str.length() == 0)
        return "";

    // recursive call
    string rem_string = move(str.substr(1));

    // condition checking
    if (str[0] == 'x')
        return rem_string + str[0];
    return str[0] + rem_string;
}

int main()
{
    string str = "axxbdxcefxhix";
    cout << move(str);
    return 0;
}