#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int st, int mid, int end){
    int n = end-st+1;
    int result[n];
    int i=0, k=0;
    int j=mid+1;

    while(i<=mid && j<=end){
        if(arr[i] < arr[j])
            result[k++] = arr[i++];

        else
            result[k++] = arr[j++];

    }
    while(i<=mid)
        result[k++] = arr[i++];

    while(j<=end)
        result[k++] = arr[j++];

    for(int x=0 ; x<n ; x++)
        arr[x] = result[x];
}

void merge_sort(int arr[], int st, int end){
    if(st<end){
        int mid = (st+end)/2;
        merge_sort(arr, st, mid);
        merge_sort(arr, mid+1, end);

        merge(arr, st, mid, end);
    }
}

int main()
{
    int arr[] = {6, 3, 9, 5, 2, 8, 7, 1};
    int n=8;

    int st=0;
    int end=n-1;

    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;

    merge_sort(arr, st, end);

    for(int i=0; i<n; i++)
        cout << arr[i] << " ";

    return 0;
}