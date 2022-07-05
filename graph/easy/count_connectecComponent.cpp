// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

/*
Approach
1. make a visited array containing all nodes
2. start a loop over visited array

    if element not visited (i.e. vis[element] == 0) make a dfs call to it
    vis[1, 0, 1]        // 1 and 3 will be marked visited
    then increment count++
*/

void dfs(int v, vector<vector<int>> adj, vector<int> &visited){
    visited[v] = 1;
    for(int i=1; i <= adj[v].size(); i++)
    {
        int child = adj[v][i];
        if(visited[child] == 0)
            dfs(child, adj, visited);
    }
}



int numProvinces(vector<vector<int>> adj, int n) {
    vector<int> visited(n);

    int count=0;
    for(int i=0; i<n; i++){
        if(visited[i] == 0){
            dfs(i, adj, visited);
            count++;
        }
    }

    return count;
}