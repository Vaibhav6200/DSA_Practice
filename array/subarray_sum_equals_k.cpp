#include<bits/stdc++.h>
using namespace std;


int kadane(int nums[], int n, int target){
    int currSum=0;
    int count=0;

    for(int i=0; i<n; i++){
        currSum += nums[i];

        if(currSum < 0)
            currSum = 0;

        if(currSum==target){
            count++;
            currSum = 0;
            if(!(nums[i]==target))
            i--;
        }

        if(currSum > target){
            currSum = 0;
            i--;
        }
    }
    return count;
}

int main()
{
    int arr[] = {1, 2, 3};
    int n = 3;
    int k = 3;
    cout << kadane(arr, n, k);

    return 0;
}