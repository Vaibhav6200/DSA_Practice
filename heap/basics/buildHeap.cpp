#include<bits/stdc++.h>
using namespace std;


void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}


void heapify(int arr[], int size, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if((left <= size) && (arr[largest] < arr[left]))
            largest = left;

    if((right <= size) && (arr[largest] < arr[right]))
            largest = right;

    if(largest != i){       // means largest was updated to new max value so we have to swap it
        swap(&arr[largest], &arr[i]);
        heapify(arr, size, largest);
    }
}


int main()
{
    int arr[] = {-1, 1, 2, 3, 4, 5};
    int size = 5;

    for(int i=size/2; i>0; i--)
        heapify(arr, size, i);

    for(int i=1; i<=size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}