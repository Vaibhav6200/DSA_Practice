#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
/*
    *** APPROACH ***
1. Make a dfsVisited array to track whose dfs call is still ON
2. if dfsVisited[node] == 1 and visited[node] == 1
    Means Cycle DETECTED
*/


    bool isCyclicDFS(int node, vector<int> &visited, vector<int> &dfsVisited, vector<int> adj[])
    {
        visited[node] = 1;
        dfsVisited[node] = 1;

        for(auto neighbour: adj[node])
        {
            if(!visited[neighbour]){
                bool flag = isCyclicDFS(neighbour,  visited, dfsVisited, adj);
                if(flag)
                    return true;
            }
            else if(dfsVisited[neighbour])
                return true;
        }

        dfsVisited[node] = 0;
        return false;
    }

    bool isCyclic(int n, vector<int> adj[]) {
        vector<int> visited(n);
        vector<int> dfsVisited(n);

        for(int i=0; i<n; i++){
            if(!visited[i]){
                bool flag = isCyclicDFS(i, visited, dfsVisited, adj);

                if(flag)
                    return true;
            }
        }
        return false;
    }
};


int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}