/*
    *** APPROACH ***
Finding MST using prim algo and then we will take sum of all values in "key" array
*/
#include<bits/stdc++.h>
using namespace std;


void printList(unordered_map<int, list<pair<int, int>>> &adj){
    for(auto i: adj){
        cout << i.first << " -> ";
        for(auto j: i.second)
            cout << "{" << j.first << ", " << j.second << "} ";
        cout << endl;
    }
}


vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // create adj list
    unordered_map<int, list<pair<int, int>>> adj;
    for(int i=0; i<m; i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int wt = g[i].second;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    // create required datastructures
    vector<int> key(n+1, INT_MAX);    // we will refer index as node
    vector<bool> mst(n+1, false);
    vector<int> parent(n+1, -1);

    // initiallize source node
    key[1] = 0;

    for(int i=1; i<=n; i++){
        // find min wt node from key array
        int u;
        int mini = INT_MAX;
        for(int v=1; v<=n; v++){
            if(mst[v] == false && key[v] < mini){
                mini = key[v];
                u = v;
            }
        }

        // mark it in MST
        mst[u] = true;

        // explore neighbour vertices
        for(auto nbr: adj[u]){
            int v = nbr.first;
            int wt = nbr.second;
            if(mst[v] == false && wt < key[v]){
                key[v] = wt;
                parent[v] = u;
            }
        }
    }

    vector<pair<pair<int, int>, int>> ans;
    for(int i=2; i<=n; i++){      // starting from 1 because Node '0' parent is -1
        int u = i;
        int v = parent[i];
        int wt = key[i];
        ans.push_back({{u, v}, wt});
    }

    return ans;
}


int main()
{

    return 0;
}