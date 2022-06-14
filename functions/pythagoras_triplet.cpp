#include<bits/stdc++.h>
using namespace std;

bool check(int x, int y, int z){
    int a = max(x, max(y, z));
    int b, c;
    if(x==a){
        b = y;
        c = z;
    }
    else if(y==a){
        b = x;
        c = z;
    }
    else{
        b = x;
        c = y;
    }

    if(a*a == b*b + c*c)
        return true;
    return false;
}

int main()
{
    cout << check(6, 8, 10);
    return 0;
}