#include<bits/stdc++.h>
using namespace std;

vector<int> Sum2(vector<int> arr, int target){
    vector<int> result;
    unordered_set<int> map;
    int n = arr.size();

    for(int i=0; i<n; i++){
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

vector<vector<int>> Sum4(vector<int> arr, int target){
    vector<vector<int>> ans;

    int n = arr.size();
    vector<int> result;
    for(int i=0; i<n; i++){
        int num1 = arr[i];
        arr.erase(arr.begin() + i);
        for(int j=i+1; j<n; j++){
            int num2 = arr[j];
            arr.erase(arr.begin() + j);

            int temp = target - (num1 + num2);

            result = Sum2(arr, temp);
            result.push_back(num1);
            result.push_back(num2);

            arr.insert(arr.begin() + j, num2);
        }
        arr.insert(arr.begin() + i, num1);
        ans.push_back(result);
    }
    return ans;
}

int main()
{

    return 0;
}