#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
/*
    *** APPROACH ***
1. Check for connected components
    all edges must be present in 1 component
    remaining all vertices must have degree 0
2. count odd degree nodes
    if count == 0   => euler circuit
    if count == 2   => euler path   (st and end vertex will have odd degree)
    else return 0
*/

    void dfs(int node, vector<int> adj[], vector<bool> &visited){
        visited[node] = true;
        for(auto nbr: adj[node]){
            if(!visited[nbr])
                dfs(nbr, adj, visited);
        }
    }

    bool checkConnected(int n, vector<int> adj[]){
        vector<bool> visited(n, false);
        // find a node with degree > 0 and make a dfs call for it
        for(int i=0; i<n; i++)
            if(adj[i].size() > 0)
                dfs(i, adj, visited);

        // check rem vertices have degree == 0 if not then its not euler circuit
        for(int i=0; i<n; i++)
            if(!visited[i]){
                if(adj[i].size() > 0)
                    return false;
            }

        return true;
    }


	int isEularCircuit(int n, vector<int>adj[]){

	    if(checkConnected(n, adj)){

	        // count odd degree nodes
	        int odd = 0;
	        for(int i=0; i<n; i++){
	            int x = adj[i].size();
	            if(x%2 == 1)
	                odd++;
	        }

	        if(odd == 0)
	            return 2;
            else if(odd == 2)
                return 1;
	    }

        return 0;
	}
};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.isEularCircuit(V, adj);
		cout << ans <<"\n";	}
	return 0;
}