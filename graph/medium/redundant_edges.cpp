#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
/*
    *** APPROACH ***
1. Make Adj List
2. Find no of components using DFS
3. Find total Redundant Edges
    if(red edges >= components-1)   means we can connect all devices
        then minimum edges required to connect all components = components - 1

BASE CASES
1. Edges < n-1
2. Red Edges < components - 1
*/
    void dfs(int node, unordered_map<int, list<int>> &adj, vector<int> &visited){
        visited[node] = 1;
        for(auto nbr: adj[node])
            if(!visited[nbr])
                dfs(nbr, adj, visited);
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        // creating adjList
        int size = connections.size();
        unordered_map<int, list<int>> adj;
        for(int i=0; i<size; i++){
            int u = connections[i][0];
            int v = connections[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // count total components
        vector<int> visited(n, 0);
        int comp = 0;                  // tracks count of all components
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(i, adj, visited);
                comp++;
            }
        }


        // Count Total Redundant Edges
        int total_edges = connections.size();
        int red = total_edges - ((n-1) - (comp-1));

        if(red >= (comp-1))        // means devices can be connected
            return comp-1;

        return -1;
    }
};


int main()
{

    return 0;
}

