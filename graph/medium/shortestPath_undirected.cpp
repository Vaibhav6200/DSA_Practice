
/*
    *** APPROACH ***
1. Do BFS traversal and find parent array
2. now find shortest path from that parent array by tracking nodes from dest to src
*/

#include<bits/stdc++.h>
using namespace std;


vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
    unordered_map<int, list<int>> adj;
    vector<int> visited(n+1);
    // Step1: make adj list
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Step2 : Do BFS
    visited[s] = 1;
    queue<int> q;
    q.push(s);

    vector<int> parent(n+1);
    parent[s] = -1;
    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto i: adj[front]){
            if(!visited[i]){
                visited[i] = 1;
                q.push(i);
                parent[i] = front;
            }
        }
    }

    // Step3: make ans array (by tracking from dest to src)
    int curr = t;
    vector<int> ans;
    ans.push_back(curr);
    while(curr != s){
        curr = parent[curr];
        ans.push_back(curr);
    }

    // step4: Reverse our ans array
    reverse(ans.begin(), ans.end());
    return ans;
}


int main()
{

    return 0;
}