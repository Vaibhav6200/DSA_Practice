#include<bits/stdc++.h>
using namespace std;



/*
1. visit current vertex
2. Push it into queue
3. Now explore that vertex
*/

// since we need our answer in sorted order so we are using set instead of list in our unordered map creation

// void makeAdjList(unordered_map<int, list<int>> &adjList, vector<pair<int, int>> edges){
void makeAdjList(unordered_map<int, set<int>> &adjList, vector<pair<int, int>> edges){
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs(int node, unordered_map<int, set<int>> adjList, vector<int> &visited, vector<int> &ans){
    // step1: visit current vertex/node
    visited[node] = 1;
    queue<int> q;
    q.push(node);

    while(!q.empty()){      // for each vertex it will traverse all its adj vertices (adj vertices = no of edges)  -  time = O(E)
        int frontNode = q.front();
        q.pop();

        // store vertex in our answer and then start exploring its adj vertices
        ans.push_back(frontNode);

        for(auto i: adjList[frontNode]){
            if(visited[i] == 0){
                q.push(i);
                visited[i] = 1;
            }
        }
    }

}


vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int>> adjList;
    makeAdjList(adjList, edges);

    int n = vertex;
    vector<int> visited(n);
    vector<int> ans;

    for(int i=0; i<n; i++){
        if(visited[i] == 0)
            bfs(i, adjList, visited, ans);
    }
    return ans;
}

int main()
{

    return 0;
}