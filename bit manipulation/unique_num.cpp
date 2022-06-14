#include<bits/stdc++.h>
using namespace std;


int get_unique(int arr[], int n){
    int xorSum=0;
    for(int i=0; i<n; i++)
        xorSum = xorSum ^ arr[i];
    return xorSum;
}

int main()
{
    int arr[] = {2, 4, 6, 4, 5, 6, 2};
    int n=7;
    int num = get_unique(arr, n);
    cout << num;

    return 0;
}