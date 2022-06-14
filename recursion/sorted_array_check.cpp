#include<bits/stdc++.h>
using namespace std;

bool check(int arr[], int i, int n){
    if(i==n-1)
        return true;
    if(arr[i] < arr[i+1])
        return check(arr, i+1, n);
    return false;
}

int main()
{
    int arr[] = {1,2,3,4,5};
    cout << check(arr, 0, 5);

    return 0;
}