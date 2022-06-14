#include<bits/stdc++.h>
using namespace std;

int countWays(int m, int n, int p, int q, int i, int j){
    if(i==m-1 && j==n-1)
        return 1;
    if(i>=m || j>=n)
        return 0;
    return countWays(m, n, p, q, i+q, j) + countWays(m, n, p, q, i, j+p);
}

int main()
{
    cout << countWays(2, 4, 2, 1, 0, 0);
    return 0;
}