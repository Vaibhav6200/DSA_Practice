#include<bits/stdc++.h>
using namespace std;

void swap(int *i, int *j){
    int temp = *i;
    *i = *j;
    *j = temp;
}

void insertion_sort(int arr[], int n){
    int i, j;
    for(i=1 ; i<n ; i++){
        int curr = arr[i];
        for(j=i-1 ; arr[j]>curr && j>=0 ; j--)
            arr[j+1] = arr[j];
        arr[j+1] = curr;
    }
}

void bubble_sort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for (int j=0; j<n-i-1; j++){
            if(arr[j+1]<arr[j])
                swap(&arr[i], &arr[j]);
        }
    }
}

void selection_sort(int arr[], int n){
    int pos;
    for(int i=0 ; i<n; i++){
        int min=arr[i];
        for(int j=i ; j<n ; j++){
            if(arr[j]<min){
                min = arr[j];
                pos = j;
            }
        }
        swap(&arr[i], &arr[pos]);
    }
}


int main()
{

    int n=5;
    int arr[] = {8, 5, 7, 2, 3};

    // insertion_sort(arr, n);
    // bubble_sort(arr, n);
    selection_sort(arr, n);

    for (int i=0 ; i<n ; i++)
        cout << arr[i] << " ";
    return 0;
}