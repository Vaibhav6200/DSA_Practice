/*
    *** APPROACH ***
1. Find topological Sort
2. find Transpose of given graph (this will trap all SCC within themselves)
3. Make DFS call in topological sort order
*/

#include<bits/stdc++.h>
using namespace std;


void topologicalSort(int node, unordered_map<int, list<int>> &adj, vector<int> &vis, stack<int> &st)
{
    vis[node] = 1;
    for(auto i: adj[node]){
        if(!vis[i])
            topologicalSort(i, adj, vis, st);
    }
    st.push(node);
}

void dfs(int node, unordered_map<int, list<int>> &adj, vector<int> &vis, vector<int> &result)
{
    vis[node] = 1;
    result.push_back(node);
    for(auto i: adj[node]){
        if(!vis[i])
            dfs(i, adj, vis, result);
    }
}

void revDfs(int node, unordered_map<int, list<int>> &transpose, vector<int> &vis){
    vis[node] = 1;
    cout << node << " -> ";
    for(auto i: transpose[node]){
        if(!vis[node])
            revDfs(i, transpose, vis);
    }
}

void print(vector<int> temp){
    for(int i=0; i<temp.size(); i++)
        cout << temp[i] << " ";
    cout << endl;
}

void printList(unordered_map<int, list<int>> adj){
    for(auto i: adj){
        cout << i.first << " -> ";
        for(int j: i.second)
            cout << j << " ";
        cout << endl;
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges){
    // create adjacency List
    unordered_map<int, list<int>> adj;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // find order
    vector<int> vis(v, 0);
    vector<int> order;
    for(int i=0; i<v; i++){
        if(!vis[i])
            dfs(i, adj, vis, order);
    }

    // Transpose graph
    unordered_map<int, list<int>> transpose;
    for(int i=0; i<v; i++){
        vis[i] = 0;         // reinitiallizing vis for further use
        for(auto nbr: adj[i])
            transpose[nbr].push_back(i);
    }

    printList(transpose);
    // iterate in order
    print(order);
    for(auto i: order){
        if(!vis[i]){
            revDfs(i, transpose, vis);
            cout << endl;
        }
    }
}

int main()
{

    return 0;
}
