// Used to find max Subarray sum --> O(n)

#include<bits/stdc++.h>
using namespace std;

int main()
{
    // [4,5,0,-2,-3,1]
    int arr[] = {4, 5, 0, -2, -3, 1};
    int len=sizeof(arr)/sizeof(arr[0]);

    int currSum=0;
    int max_sum = INT_MIN;

    for(int i=0; i<len; i++){
        currSum+=arr[i];

        if(currSum<0)
            currSum=0;

        max_sum=max(max_sum, currSum);        // Updating max_sum variable
    }
    cout << max_sum;

    return 0;
}