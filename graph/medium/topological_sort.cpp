#include <bits/stdc++.h>
using namespace std;


class Solution
{
	public:
/*
    *** APPROACH ***
1. Do DFS traversal
2. While returning from DFS push that node into stack
*/

    void dfs(int node, vector<int> adj[], vector<int> &visited, stack<int> &st)
    {
        visited[node] = 1;
        for(auto neighbour: adj[node])
        {
            if(!visited[neighbour]){
                dfs(neighbour, adj, visited, st);
            }
        }
        st.push(node);
    }

	vector<int> topoSort(int n, vector<int> adj[])
	{
	    vector<int> ans;
	    vector<int> visited(n);
	    stack<int> st;


	    for(int i=0; i<n; i++){
	        if(!visited[i])
	            dfs(i, adj, visited, st);
	    }

	    while(!st.empty()){
	        int x = st.top();
            st.pop();

            ans.push_back(x);
	    }


	    return ans;
	}
};


int check(int V, vector <int> &res, vector<int> adj[]) {

    if(V!=res.size())
    return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }

    return 0;
}