// Finding All Possible Subarrays in O(n^2) Time Complexity

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = {1, 2, 3, 4};
    int n=4;

    vector<vector<int>> result;

    for (int i=0; i<n; i++){
        vector<int> temp;
        for (int j=i; j<n; j++){
            temp.push_back(a[j]);
            result.push_back(temp);
        }
    }
    // int row_size = result.size();
    // int col_size = result[i].size();    // NOTE: Col Size would be variable

    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
    return 0;
}