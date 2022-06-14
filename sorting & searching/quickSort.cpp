#include<bits/stdc++.h>
using namespace std;

void swap(int* i, int *j){
    int temp=*i;
    *i=*j;
    *j=temp;
}

int partition(int arr[], int st, int end){
    int i=st;
    int j=end;
    int pivot=arr[st];

    while(i<j){
        do{
            i++;
        }while(arr[i]<=pivot);

        do{
            j--;
        }while(arr[j]>pivot);

        if(i<j)
            swap(&arr[i], &arr[j]);
    }
    swap(&arr[st], &arr[j]);
    return j;
}

void quickSort(int arr[], int st, int end){
    if(st<end){
        int p = partition(arr, st, end);
        quickSort(arr, st, p);
        quickSort(arr, p+1, end);
    }
}

int main()
{
    int arr[] = {6, 3, 9, 5, 2, 8, 7, INT_MAX};
    int n=8;
    int st=0;
    int end=n-1;
    quickSort(arr, st, end);

    for(int i=0; i<end; i++)
        cout << arr[i] << " ";

    return 0;
}