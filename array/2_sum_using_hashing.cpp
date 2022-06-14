#include<bits/stdc++.h>
using namespace std;


vector<int> sum2(vector<int> arr, int target){
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

    return 0;
}