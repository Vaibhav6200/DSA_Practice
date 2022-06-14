// Sum of 3 pairs from an array equal to k (target)

#include<bits/stdc++.h>
using namespace std;

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

vector<int> twoSum(vector<int> array,int st, int target){
    vector<int> v;
    for(int i=st; i<array.size(); i++){
        for(int j=i+1; j<array.size(); j++){
            if(array[i]+array[j]==target){
                v.push_back(array[i]);
                v.push_back(array[j]);
                return v;
            }
        }
    }
    return v;
}

vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        sort(nums);

        vector<int> v;
        int curr;
        for(int i=0; i<nums.size(); i++){
            curr=nums[i];
            v = twoSum(nums, i+1, -curr);
            if(!v.empty()){     // means we found a triplet so add it to our result
                v.push_back(curr);   // appending 3rd element in our vector
                result.push_back(v);    // pushing our vector/triplet in our result
            }
        }

     return result;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> result;


    return 0;
}