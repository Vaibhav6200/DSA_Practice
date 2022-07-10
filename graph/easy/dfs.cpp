#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  /*
    Approach

STEP1: visit vertex v
STEP2: Explore its adjacency list
        if any element is not visited then repeat same procedure for that element
  */
void dfs(int v, vector<int> adj[], vector<int> &visited, vector<int> &ans){

    // Step1: Visit vertex v
    visited[v] = 1;
    ans.push_back(v);

    // Step2: Explore vertex v
    int size = adj[v].size();
    for(int i=0; i<size; i++)
    {
        int child = adj[v][i];

        if(visited[child] == 0)
            dfs(child, adj, visited, ans);
    }
}

    vector<int> dfsOfGraph(int n, vector<int> adj[]) {
        vector<int> ans;
        vector<int> visited(n);

        dfs(0, adj, visited, ans);

        return ans;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}