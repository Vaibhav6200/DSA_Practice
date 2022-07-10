/* CASE: when we dont include (parent == -1 && child > 1)
7 6                      4
5 0                    / | \
4 6                   3  6  0
1 3                  /   |   \
5 2                 1    7    5
0 4                            \
4 3                             2
                our output - 3 4 5
                code output - 0 3 4 5
*/


#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low,
            vector<bool> &vis, unordered_map<int, list<int>> &adj, vector<int> &artPoint)
    {
        vis[node] = true;
        disc[node] = low[node] = timer++;

        // discover neighbour nodes
        int child=0;
        for(auto nbr: adj[node])
        {
            if(nbr == parent)
                continue;
            if(!vis[nbr])
            {
                dfs(nbr, node, timer, disc, low, vis, adj, artPoint);
                // after returning update low (because nbr can have back edge)
                low[node] = min(low[node], low[nbr]);

                // Check whether current node is articulation point or not
                if(low[nbr] >= disc[node] && parent != -1)
                    artPoint[node] = 1;

                child++;
            }
            // Back Edge: Update low pointer
            else
                low[node] = min(low[node], disc[nbr]);

        }
        if(parent == -1 && child>1)
            artPoint[node] = 1;
    }

    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // create adj list
        unordered_map<int, list<int>> adjList;
        for(int i=0; i<V; i++){
            for(auto j: adj[i])
                adjList[i].push_back(j);
        }

        // create required datastructures and initiallize them
        vector<int> disc(V, -1);        // all disc elements will be initiallized with -1
        vector<int> low(V, -1);
        vector<bool> vis(V, false);
        int parent = -1;
        int timer = 0;

        // do DFS and for each node check whether its articulation point or not
        // handling non connected component case
        vector<int> artPoint(V, 0);
        for(int i=0; i<V; i++){
            if(!vis[i])
                dfs(i, parent, timer, disc, low, vis, adjList, artPoint);
        }


        vector<int> result;
        bool flag = false;
        for(int i=0; i<V; i++){
            if(artPoint[i] != 0){
                result.push_back(i);
                flag = true;
            }
        }
        if(!flag)   // handling case when there is no articulation point
            result.push_back(-1);

        return result;
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
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}