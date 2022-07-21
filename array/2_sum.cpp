// Sum of 2 pair from an array equal to k (target)

#include<bits/stdc++.h>
using namespace std;


// Method 1: (Using 2 For Loops) Time Complexity => O(n^2)
vector<int> twoSum1(vector<int> &arr, int target){
    vector<int> v;
    for(int i=0; i<arr.size(); i++){
        for(int j=i+1; j<arr.size(); j++){
            if(arr[i]+arr[j]==target){
                v.push_back(arr[i]);
                v.push_back(arr[j]);
                return v;
            }
        }
    }
    return v;
}


// Method 2: Time Complexity => O(n) if array is sorted and if its not sorted then time complexity is same as that of sorting algorithm
vector<int> twoSum2(vector<int> &arr, int target){
    vector<int> result;
    sort(arr.begin(), arr.end());
    int low = 0;
    int high = arr.size() - 1;

    while(low < high){
        if(arr[low] + arr[high] == target){
            result.push_back(arr[low]);
            result.push_back(arr[high]);
            return result;
        }
        else if(arr[low]+arr[high] < target)
            low++;
        else
            high--;
    }
    return result;
}


// Method 3: Using Hashing  (Time - O(n))
vector<int> twoSum3(vector<int> arr, int target){
    vector<int> result;
    unordered_set<int> map;

    for(int i=0; i<arr.size(); i++){
        int temp = target - arr[i];
        if(map.count(temp) > 0){
            result.push_back(arr[i]);
            result.push_back(temp);
            return result;
        }
        map.insert(arr[i]);
    }
    return result;
}


int main()
{
    vector<int> arr = {2, 4, 7, 11, 14, 16, 20, 21};
    int target = 31;
    vector<int> result;
    result = twoSum3(arr, target);
    int sum=0;

    for(int i=0; i<result.size(); i++)
        cout << result[i] << " ";

    return 0;
}