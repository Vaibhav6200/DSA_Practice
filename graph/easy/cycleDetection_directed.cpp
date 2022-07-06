// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
/*
    *** APPROACH 1 (Using DFS) ***
1. Here We have to Track DFS calls
    so we will make a DFSvisited array which tracks whose DFS calls are still remaininig and whose
    calls are completed

2. If a neighbour is visited and its DFSvisited is still true means cycle detected
*/


/*
    *** APPROACH 2 (Using BFS) ***
1. find topological sort (Using Khan's Algorithm) (BFS wali Approach)
2. if we get invalid topological sort then return true (means cycle present)
NOTE: we get valid topological sort only for acyclic graphs
ALSO: Valid Means (Topological Sort.size() == no of vertices)
*/

    bool isCycleDFS(int node, vector<int> &visited, vector<int> &dfsVisited, vector<int> adj[]){
        visited[node] = 1;
        dfsVisited[node] = 1;

        // exploring neighbouring vertices
        for(auto neighbour: adj[node]){
            if(!visited[neighbour]){
                bool flag = isCycleDFS(neighbour, visited, dfsVisited, adj);
                if(flag)
                    return true;
            }
            else if(dfsVisited[neighbour])
                return true;
        }

        dfsVisited[node] = 0;
        return false;
    }


    // do dfs and push all end nodes in stack
    void topologicalSort(int node, vector<int> &visited, stack<int> &st, vector<int> adj[]){
        visited[node] = 1;
        for(auto neighbour: adj[node]){
            if(!visited[neighbour]){
                topologicalSort(neighbour, visited, st, adj);
            }
        }

        st.push(node);
    }


int isCycleBFS(int n, vector<int> adj[]) {

    // make indegree array
    vector<int> indegree(n);
    for(int i=0; i<n; i++){
        for(auto j: adj[i])
            indegree[j]++;
    }

    // push all nodes with indegree 0 in queue
    queue<int> q;
    for(int i=0; i<n; i++){
        if(indegree[i] == 0)
            q.push(i);
    }

    // do bfs traversal
    int count=0;
    while(!q.empty()){
        int front = q.front();
        q.pop();

        count++;

        // update neighbour nodes
        for(auto neighbour: adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }

    if(count == n)        // Valid Topological Sort: So Graph = Acyclic
        return false;
    return true;
}


    bool isCyclic(int n, vector<int> adj[]) {
        vector<int> visited(n);
        vector<int> dfsVisited(n);


        // METHOD 1
        // handling case of non connected components
        // for(int i=0; i<n; i++){
        //     if(!visited[i]){
        //         bool flag = isCycleDFS(i, visited, dfsVisited, adj);

        //         if(flag)
        //             return true;
        //     }
        // }
        // return false;


        // METHOD 2
        // handling case of non connected components
        return isCycleBFS(n, adj);

        // while(!st.empty()){
        //     cout << st.top() << " ";
        //     st.pop();
        // }
        // cout << endl;
        // if(st.size() == n)
        //     return false;
        // return true;
    }
};

// { Driver Code Starts.

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
  // } Driver Code Ends