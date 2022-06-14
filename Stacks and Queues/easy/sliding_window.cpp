// OPTIMISED APPROACH


// BRUTE FORCE APPROACH
#include<bits/stdc++.h>
using namespace std;

int findMax(vector<int> arr){
    int n = arr.size();
    int maximum = INT_MIN;
    for(int i=0; i<n; i++)
        maximum = max(maximum, arr[i]);
    return maximum;
}

int max_of_min_windows(int arr[], int n, int windowSize){
    vector<int> result;
    for(int i=0; i<=n-windowSize ; i++){
        int minimum = INT_MAX;
        for(int j=i; j<windowSize+i; j++)
            minimum = min(minimum, arr[j]);
        result.push_back(minimum);
    }

    int max = findMax(result);
    return max;
}

vector <int> maxOfMin(int arr[], int n){
    vector<int> ans;
    for(int i=1; i<=n; i++){
        int x = max_of_min_windows(arr, n, i);
        ans.push_back(x);
    }
    return ans;
}

int main()
{
    vector<int> arr;
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(50);
    arr.push_back(10);
    arr.push_back(70);
    arr.push_back(30);

    int windowSize = 2;


    return 0;
}