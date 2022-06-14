#include<bits/stdc++.h>
using namespace std;

int getBit(int n, int pos){
    return (n&(1<<pos));
}

int setBit(int n, int pos){
    return (n|(1<<pos));
}

int clearBit(int n, int pos){
    int mask = ~(1<<pos);
    return (n & mask);
}

int update(int n, int pos, int value){
    int mask = ~(1<<pos);
    n = n & mask;
    return n | (value << pos);
}

int main()
{
    int n = 6;
    int pos = 2;
    int ans = clearBit(n, pos);
    // cout << ans;

    ans = 1<<2;
    cout << ans;
    return 0;
}