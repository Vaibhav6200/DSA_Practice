#include<bits/stdc++.h>
using namespace std;


int find_peak(int arr[], int st, int end){
    int mid = st + (end-st)/2;

    if(arr[mid] > arr[mid+1] && arr[mid]>arr[mid-1]){
        return mid;
    }
    else if(arr[mid+1] > arr[mid])
        return find_peak(arr, mid+1, end);
    else
        return find_peak(arr, st, mid-1);
}

int main()
{
    int arr[] = {5, 10, 20, 15};
    int n=4;
    int st=0;
    int end=n-1;
    cout << find_peak(arr, st, end);
    return 0;
}