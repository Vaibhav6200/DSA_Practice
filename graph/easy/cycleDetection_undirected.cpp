#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    bool isCycleBFS(int v, vector<int> &visited, vector<int> adj[]){
        unordered_map<int, int> parent;     // child to parent mapping

        parent[v] = -1;     // parent of started vertex is set to -1
        visited[v] = 1;
        queue<int> q;
        q.push(v);

        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(auto neighbour: adj[front]){
                if(visited[neighbour] == true && neighbour != parent[front])
                    return true;

                else if(!visited[neighbour]){
                    parent[neighbour] = front;      // setting parent of front node
                    visited[neighbour] = 1;
                    q.push(neighbour);
                }
            }
        }
        return false;
    }


    bool isCycleDFS(int node, int parent, vector<int> &visited, vector<int> adj[]){
        visited[node] = 1;

        for(auto neighbour: adj[node]){
            if(!visited[neighbour]){
                bool cycleDetected =  isCycleDFS(neighbour, node, visited, adj);
                if(cycleDetected)
                    return true;
            }
            else if(neighbour != parent)
                return true;
        }
        return false;
    }


    bool isCycle(int n, vector<int> adj[]) {
        vector<int> visited(n);

        // // USING BFS
        // for(int i=0; i<n; i++){
        //     if(!visited[i]){
        //         bool flag = isCycleBFS(i, visited, adj);

        //         if(flag)
        //             return true;
        //     }
        // }


        // USING DFS
        for(int i=0; i<n; i++){
            if(!visited[i]){
                bool flag = isCycleDFS(i, -1, visited, adj);

                if(flag)
                    return true;
            }
        }
        return false;
    }
};


int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends