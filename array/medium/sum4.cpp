#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
//  *** APPROACH 2 ***
    vector<vector<int>> fourSum(vector<int>& arr, int target)
    {
        set<vector<int>> ans;       // using for optimization
        int n = arr.size();

        sort(arr.begin(), arr.end());

        for(int i=0; i<n-3; i++)
        {
            if(i>0 && arr[i] == arr[i-1])       // skipping duplicates
                continue;

            for(int j=i+1; j<n-2; j++)
            {
                if(j>i+1 && arr[j] == arr[j-1])     // skipping duplicates
                    continue;

                int left = j+1;
                int right = n-1;

                while(left < right){
                    long long sum = (long long)arr[i] + arr[j] + arr[left] + arr[right];
                    if(sum > target)
                        right--;
                    else if(sum < target)
                        left++;
                    else{
                        vector<int> temp;
                        temp.push_back(arr[i]);
                        temp.push_back(arr[j]);
                        temp.push_back(arr[left]);
                        temp.push_back(arr[right]);
                        ans.insert(temp);
                        left++;
                    }
                }
            }
        }

        vector<vector<int>> result;
        for(auto x: ans)
            result.push_back(x);

        return result;
    }

//  *** APPROACH 3 ***

//     vector<vector<int>> fourSum(vector<int>& arr, int target) {
//         vector<vector<int>> ans;
//         int n = arr.size();
//         if(n < 4)
//             return ans;

//         sort(arr.begin(), arr.end());
//         unordered_map<int, vector<pair<int, int>> > map;

//         // find all possible 2 sums and store in HashMap
//         for(int i=0; i<n-1; i++){
//             for(int j=i+1; j<n; j++){
//                 int sum = arr[i] + arr[j];
//                 map[sum].push_back({i, j});
//             }
//         }

//         // for(auto i: map){
//         //     cout << i.first << " -> ";
//         //     for(auto j: i.second)
//         //         cout << "{" << j.first << ", " << j.second << "} ";
//         //     cout << endl;
//         // }

//         for(int i=0; i<n-1; i++){
//             if(i>0 && arr[i] == arr[i-1])     // skipping duplicates
//                 continue;
//             for(int j=i+1; j<n; j++){
//                 if(j>i+1 && arr[j] == arr[j-1])   // skipping duplicates
//                     continue;
//                 long long sum = (long long) target - (long long) (arr[i] + arr[j]);
//                 if(map.find(sum) != map.end()){
//                     for(auto x: map[sum]){
//                         int k = x.first;
//                         int l = x.second;
//                         if(j < k){      // maintaining increasing order of i, j, k, l

//                             // removing duplicates
//                             if(!ans.empty() && (ans.back()[0] == arr[i] && ans.back()[1] == arr[j] && ans.back()[2] == arr[k] && ans.back()[3] == arr[l]))
//                                 continue;
//                             vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
//                             ans.push_back(temp);
//                         }
//                     }
//                 }
//             }
//         }

//         return ans;
//     }
};