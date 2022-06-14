// print increasing and decreasing number


#include<bits/stdc++.h>
using namespace std;

void inc(int n){
    if(n==1){
        cout << n << " ";
        return;
    }
    inc(n-1);
    cout << n << " ";
}

void dec(int n){
    if(n==1){
        cout << n << " ";
        return;
    }
    cout << n << " ";
    dec(n-1);
    return;
}

int main()
{
    inc(10);
    cout << endl;
    dec(10);
    return 0;
}