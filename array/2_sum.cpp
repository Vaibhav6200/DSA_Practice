// Sum of 2 pair from an array equal to k (target)

#include<bits/stdc++.h>
using namespace std;

// Method 1: (Using 2 For Loops) Time Complexity => O(n^2)
// vector<int> twoSum(vector<int> &arr, int target){
//     vector<int> v;
//     for(int i=0; i<arr.size(); i++){
//         for(int j=i+1; j<arr.size(); j++){
//             if(arr[i]+arr[j]==target){
//                 v.push_back(arr[i]);
//                 v.push_back(arr[j]);
//                 return v;
//             }
//         }
//     }
//     return v;
// }


// Method 2: Time Complexity => O(n) if array is sorted and if its not sorted then time complexity is same as that of sorting algorithm
void sort(vector<int>& nums){
    int n=nums.size();

//  STEP1 : Sorting Array
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(nums[j]>nums[j+1]){
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }
}


vector<int> twoSum(vector<int> &arr, int target){
    vector<int> result;
    sort(arr);
    int low = 0;
    int high = arr.size() - 1;

    while(low<high){
        if(arr[low] + arr[high] == target){
            result.push_back(arr[low]);
            result.push_back(arr[high]);
            return result;
        }
        else if(arr[low]+arr[high]<target)
            low++;
        else
            high--;
    }
    return result;
}

int main()
{
    vector<int> arr = {2, 4, 7, 11, 14, 16, 20, 21};
    int target = 31;
    vector<int> result;
    result = twoSum(arr, target);
    int sum=0;

    for(int i=0; i<result.size(); i++)
        cout << result[i] << " ";

    return 0;
}