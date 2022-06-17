#include<bits/stdc++.h>
using namespace std;

vector<int> next_max_element(vector<int> arr){
    int n = arr.size();
    vector<int> result(n);

//       STEP1: Initializing stack with a very large number
    int infinity = INT_MAX;
    stack<int> st;
    st.push(infinity);

    for(int i=n-1; i>=0; i--){
        while(st.top() < arr[i])
            st.pop();
        result[i] = st.top();
        st.push(arr[i]);
    }

//         Placing -1 at those positions where INT_MAX is present in our resultant array
    for(int i=0; i<n; i++){
        if(result[i] == infinity)
            result[i] = -1;
    }
    return result;
}

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> nextMax = next_max_element(nums2);

    unordered_map<int, int> map;
    int n1 = nums1.size();
    vector<int> ans(n1);

//         Mapping all nums2 element with their indexes to reduce time complexity
    for(int i=0; i<nums2.size(); i++)
        map[nums2[i]] = i;

//         Finding next max elements for all elements in nums1 array and putting it in our ans array
    for(int i=0; i<nums1.size(); i++){
        int n = nums1[i];
        int idx = map[n];   // It will give the index of nums1[i] element
        ans[i] = nextMax[idx];
    }

    return ans;
}

int main()
{

    return 0;
}