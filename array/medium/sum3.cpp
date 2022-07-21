#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
/*
    We Have To make sure that both 2sum and 3sum does not generates duplicates
for 3 Sum To remove duplicated sort array and check:
    if(arr[i] == arr[i-1])  ==>  continue;

for 2 Sum to remove duplicates



*/

    // THIS 2 SUM CODE WILL GENERATE DUPLICATES (e.g.  [1, 2, 2])
//     vector<vector<int>> twoSum(int start, vector<int> &arr, int target){
//         unordered_map<int, int> map;
//         int n = arr.size();
//         vector<vector<int>> ans;

//         for(int i=start; i<n; i++){
//             int x = target - arr[i];
//             if(map.count(x) > 0){
//                 vector<int> temp;
//                 temp.push_back(x);
//                 temp.push_back(arr[i]);
//                 ans.push_back(temp);
//             }
//             map[arr[i]] = i;
//         }
//         return ans;
//     }

    // 2 sum without duplicates in a sorted array
    vector<vector<int>> twoSum(int start, vector<int> &arr, int target){
        vector<vector<int>> ans;
        int left = start;
        int right = arr.size() - 1;

        while(left < right){
            if(arr[left] + arr[right] > target)
                right--;

            else if(arr[left] + arr[right] < target)
                left++;

            else{
                vector<int> temp;
                temp.push_back(arr[left]);
                temp.push_back(arr[right]);
                ans.push_back(temp);

                left++;
                while(arr[left] == arr[left-1] && left < right)
                    left++;
            }
        }
        return ans;
    }

    vector<vector<int>> threeSum(vector<int>& arr) {
        vector<vector<int>> ans;
        int n = arr.size();

        // Step1: Sort our array
        sort(arr.begin(), arr.end());


        for(int i=0; i<n-2; i++)
        {
            int target = -arr[i];
            vector<vector<int>> temp = twoSum(i+1, arr, target);

            if(i != 0 && arr[i] == arr[i-1])
                continue;

            if(!temp.empty()){     // we got our answer
                for(auto x: temp){
                    vector<int> result;
                    result.push_back(arr[i]);
                    result.push_back(x[0]);
                    result.push_back(x[1]);
                    ans.push_back(result);
                }
            }
        }

        return ans;
    }
};