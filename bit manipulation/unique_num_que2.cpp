// Write a program to find a unique no in an array where all numbers except one are present thrice

#include<bits/stdc++.h>
using namespace std;

int getBit(int n, int pos){
    return (n & (1<<pos));
}

int setBit(int n, int pos){
    return (n | (1<<pos));
}

int unique(int arr[], int n){
    int result=0;

    // considering each number in an array to be 4 bytes
    for(int i=0; i<32; i++){
        int count=0;    // keeps a track of each bit
        // counting ith bit kis kis ki set hai
        for(int j=0; j<n; j++){
            if( getBit(arr[j], i) )
                count++;
        }

        if(count%3 !=0)
            result = setBit(result, i);
    }
    return result;
}

int main()
{
    int arr[] = {1,1,1,2,2,2,7,3,3,3};
    int n = 10;
    int ans = unique(arr, n);
    cout << ans;

    return 0;
}