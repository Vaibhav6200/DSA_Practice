#include<bits/stdc++.h>
using namespace std;


/*
    Approach

push all elements of array b into array a and then heapify array a
NOTE: here we follow 0-based indexing

*/
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapify(vector<int> &arr, int i, int size){

    int largest = i;
    int leftChild = 2*i + 1;
    int rightChild = 2*i + 2;

    if(leftChild < size && arr[largest] < arr[leftChild])
        largest = leftChild;

    if(rightChild < size && arr[largest] < arr[rightChild])
        largest = rightChild;

    if(largest != i){
        swap(&arr[largest], &arr[i]);
        heapify(arr, largest, size);
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {

    for(int i=0; i<b.size(); i++)
        a.push_back(b[i]);


    int size = a.size();
    for(int i=size/2-1; i>=0; i--)
        heapify(a, i, size);

    return a;
}