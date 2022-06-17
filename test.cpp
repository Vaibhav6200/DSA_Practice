#include<bits/stdc++.h>
using namespace std;

int main()
{
    int petrol[] = {4, 6, 7, 4};
    int Distance[] = {6, 5, 3, 5};
    int n = 4;

    int i=0, j;

    while(i<n){
        j=i;
        int sum = 0;
        while(true){
            if(j==n) j=0;   // making circular loop
            if(i==j) break;    // loop will end at same position
            sum += petrol[j] - Distance[j];
            j++;
            if(sum<0) break;    // if sum negative means petrol insufficient
        }
        if(sum<0)
            i++;
        else
            cout << j;
    }

    return 0;
}