#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
/*
    *** APPROACH ***
we will be doing graph coloring for determining bipartite graph
if no ambiguity found while coloring then we return true
if ambiguity found means there is a odd length cycle in graph
and we cannot partition a graph into 2 sets if it has odd length cycle

*/

    bool bfs(int node, vector<int> &color, vector<int> adj[]){
        queue<int> q;
        q.push(node);
        color[node] = 1;

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            // color neighbour vertices
            for(auto nbr: adj[curr]){
                if(color[nbr] == color[curr])
                    return false;

                if(color[nbr] == -1){
                    color[nbr] = 1 - color[curr];
                    q.push(nbr);
                }
            }
        }

        return true;
    }

	bool isBipartite(int n, vector<int>adj[]){
        vector<int> color(n, -1);

        // handling multicomponent graph case
        for(int i=0; i<n; i++){
            if(color[i] == -1){
                bool flag = bfs(i, color, adj);
                if(flag == false)   // if any component is not bipartite then whole graph is not bipartite
                    return false;
            }
        }
        return true;
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
		bool ans = obj.isBipartite(V, adj);
		if(ans)cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}