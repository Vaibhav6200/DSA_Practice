/*
    APPROACH
Step1: create a max heap for first k elements
Step2: Now for remaining k to n-1th elements
    check if heap.top > element
        if yes then swap(heap.top, element)
Step3: after completion of this step2 we will get a max heap of k smallest elements of the array
now to get Kth Smallest element simply return heap.top

*/

#include<bits/stdc++.h>
using namespace std;


int kthSmallest(int arr[], int l, int r, int k) {
    priority_queue<int> pq;     // creates a max heap

    for(int i=0; i<k; i++)
        pq.push(arr[i]);

    for(int i=k; i<=r; i++){
        if(arr[i] < pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();
}
int main()
{

    return 0;
}

