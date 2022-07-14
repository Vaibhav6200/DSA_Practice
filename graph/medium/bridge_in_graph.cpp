#include<bits/stdc++.h>
using namespace std;


void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, vector<bool> &vis, unordered_map<int, list<int>> &adj, vector<vector<int>> &result)
{
    // step1: mark node as visited
    vis[node] = true;
    // step2: update discovery array and low arrive time array
    disc[node] = low[node] = timer++;

    // step3: Explore Neighbour vertices
    for(auto nbr: adj[node]){
        // Case1: neighbour is parent node => ignore it
        if(nbr == parent)
            continue;
        // Case2: neighbour is non visited node
        if(!vis[nbr]){
            // make dfs call for neighbour node
            dfs(nbr, node, timer, disc, low, vis, adj, result);
            // while returning update low array of node -- because its child may have backedge
            low[node] = min(low[node], low[nbr]);

            // check whether current node-nbr is a back edge or not
            if(low[nbr] > disc[node]){
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }
        // Case3: neighbour is visited => BACK EDGE case -- update lowest arrival time of node
        else
            low[node] = min(low[node], disc[nbr]);
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {

    unordered_map<int, list<int>> adj;
    // create adj list
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // create required datastructures
    int timer=0;
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    vector<bool> vis(v, false);
    int parent = -1;

    vector<vector<int>> result;
    // dfs
    // handling non connected component
    for(int i=0; i<v; i++){
        if(!vis[i])
            dfs(i, parent, timer, disc, low, vis, adj, result);
    }

    return result;
}


int main()
{

    return 0;
}