/*
USING KAHN's ALGORITHM (Topological Sort Using BFS)
    *** APPROACH ***
1. Find indegree of all nodes
2. push all nodes whose inorder is 0 in a queue
3. Do BFS
*/

#include<bits/stdc++.h>
using namespace std;


vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {

    // Making Adjacency List
    unordered_map<int, list<int>> adjList;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
    }

    // Making indegree list
    vector<int> indegree(v);
    for(auto i: adjList){
        for(auto j: i.second)
            indegree[j]++;
    }

    // Push all nodes with 0 indegree in queue
    queue<int> q;
    for(int i=0; i<v; i++){
        if(indegree[i] == 0)
            q.push(i);
    }

    // Do BFS
    vector<int> ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();

        // push front node in answer
        ans.push_back(front);

        // updating neighbouring nodes
        for(auto neighbour: adjList[front]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }
    return ans;
}


int main()
{

    return 0;
}