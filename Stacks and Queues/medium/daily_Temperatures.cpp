#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElementIndex(vector<int> arr)
{
    int n = arr.size();
    vector<int> result(n);

    int infinity = INT_MAX;
    stack<int> st;
    st.push(infinity);

    for (int i = n - 1; i >= 0; i--){
        while (st.top()!=infinity && arr[st.top()] < arr[i])
            st.pop();
        result[i] = st.top();
        st.push(i);
    }

    for (int i = 0; i < n; i++){
        if (result[i] == infinity)
            result[i] = 0;
    }

    return result;
}

vector<int> dailyTemperatures(vector<int> &temperatures){
    int n = temperatures.size();
    vector<int> ans(n);

    vector<int> next = nextGreaterElementIndex(temperatures);

    for (int i = 0; i < n; i++){
        if (next[i] == 0){
            ans[i] = 0;
            continue;
        }
        ans[i] = next[i] - i;
    }
    return ans;
}

int main()
{
// [73,74,75,71,69,72,76,73]
    vector<int> arr;
    arr.push_back(73);
    arr.push_back(74);
    arr.push_back(75);
    arr.push_back(71);
    arr.push_back(69);
    arr.push_back(72);
    arr.push_back(76);
    arr.push_back(73);

    vector<int> result;
    result = dailyTemperatures(arr);
    for(int i=0; i<result.size(); i++)
        cout << result[i] << " ";


    return 0;
}