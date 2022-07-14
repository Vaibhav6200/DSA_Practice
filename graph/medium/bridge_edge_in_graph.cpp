// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:

/*
    *** Approach 1 ***
1. Find All Bridges in graph and push that bridge's {from, to} vertex in our result vector
2. then check whether edge c-d lies in our result vector or not

    *** Approach 2 ***
1. Count SCC including our edge c--d        (count SCC using kosaraju's Algorithm)
2. Now Remove Edge c--d
3. Again Count SCC
    if number of SCC increase then return 1 else 0
*/

    void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low,
                vector<int> adj[], vector<int> &visited, vector<pair<int, int>> &result){

        visited[node] = 1;
        disc[node] = low[node] = timer++;

        for(auto nbr: adj[node]){
            if(nbr == parent)
                continue;

            if(!visited[nbr]){
                dfs(nbr, node, timer, disc, low, adj, visited, result);
                low[node] = min(low[node], low[nbr]);

                // checking condition for bridge
                if(low[nbr] > disc[node])
                    result.push_back({node, nbr});
            }
            else    // back edge
                low[node] = min(low[node], disc[nbr]);

        }
    }

    int isBridge(int n, vector<int> adj[], int c, int d)
    {
        vector<int> disc(n, -1);
        vector<int> low(n, -1);
        vector<int> visited(n, 0);
        vector<pair<int, int>> result;
        int timer=0;

        for(int i=0; i<n; i++)
            if(!visited[i])
                dfs(i, -1, timer, disc, low, adj, visited, result);

        for(auto p: result){
            int u = p.first;
            int v = p.second;

            if((u == c && v == d) || (u == d && v == c))
                return 1;
        }
        return 0;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }

        int c,d;
        cin>>c>>d;

        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends