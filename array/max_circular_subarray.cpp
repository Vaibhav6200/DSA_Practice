#include<bits/stdc++.h>
using namespace std;



int kadane(int arr[], int n){
    int currSum=0;
    int maxSum=INT_MIN;

    for(int i=0; i<n; i++){
        currSum+=arr[i];
        if(currSum<0) currSum=0;
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

int max_circular_subarray_sum(int arr[], int n){
    int totalSum=0;

    // Finding Total Sum
    for(int i=0; i<n; i++)
        totalSum+=arr[i];

    // Finding sum of non contributing elements
    for(int i=0; i<n; i++)    // Step1: reverse sign of arr
        arr[i] = -arr[i];

    int Non_contributing_sum = kadane(arr, n);    // Step2: apply Kadane Algorithm

    return (totalSum + Non_contributing_sum);
}


int main()
{
    int arr[] = {4, -4, 6, -6, 10, -11, 12};
    int n = sizeof(arr)/sizeof(arr[0]);

    int non_wrap_sum = kadane(arr, n);
    int wrap_sum = max_circular_subarray_sum(arr, n);

    cout << "Max Circular Subarray Sum: " << max(wrap_sum, non_wrap_sum);
    return 0;
}