// find first and last occurance of a number in an array

#include<bits/stdc++.h>
using namespace std;


int first_occ(int arr[], int n, int i, int target){
    if(i==n)
        return -1;

    if(arr[i] == target)
        return i;

    return first_occ(arr, n, i+1, target);
}

int last_occ(int arr[], int n, int i, int target){
    if(i==n)
        return -1;

    // we are saying pehle aage ke elements mein search kr lo then we will check our base condition
    int restArray = last_occ(arr, n, i+1, target);

    if (restArray != -1)
        return restArray;

    if(arr[i] == target)
        return i;

    return -1;
}

int main()
{
    int arr[] = {4, 2, 1, 2, 5, 2, 7};
    int n = 7;  // size of array
    int k=2;    // search key
    cout << first_occ(arr, n, 0, k) << endl << last_occ(arr, n, 0, k);

    return 0;
}