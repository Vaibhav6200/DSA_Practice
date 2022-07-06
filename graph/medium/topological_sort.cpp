#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:

/*
    *** APPROACH 1 (Using DFS) ***
1. Do DFS traversal
2. While returning from DFS push that node into stack
*/

/*
    *** APPROACH 2 (Using BFS) kahn's Algorithm ***
1. Find indegree array
2. push all nodes with degree 0 in queue
3. do BFS Traversal
*/


    void topoSort_DFS(int node, vector<int> adj[], vector<int> &visited, stack<int> &st)
    {
        visited[node] = 1;
        for(auto neighbour: adj[node])
        {
            if(!visited[neighbour]){
                topoSort_DFS(neighbour, adj, visited, st);
            }
        }
        st.push(node);
    }


    vector<int> topoSort_BFS(int v, vector<int> adj[]){
        // step1: make indegree array
        vector<int> indegree(v);
        for(int i=0; i<v; i++){
            for(auto j: adj[i])
                indegree[j]++;
        }

        // step2: push all nodes with indegree 0 in queue
        queue<int> q;
        for(int i=0; i<v; i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        // step3: do BFS
        vector<int> ans;
        while(!q.empty()){
            int front = q.front();
            q.pop();

            // push node in answer vector
            ans.push_back(front);

            // unpdate neighbouring nodes indegree
            for(auto neighbour: adj[front]){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0)
                    q.push(neighbour);
            }
        }

        return ans;
    }


	vector<int> topoSort(int n, vector<int> adj[])
	{
	   // METHOD 1: (Using DFS)
	   // vector<int> ans;
	   // vector<int> visited(n);
	   // stack<int> st;

	   // for(int i=0; i<n; i++){
	   //     if(!visited[i])
	   //         topoSort_DFS(i, adj, visited, st);
	   // }

	   // while(!st.empty()){
	   //     int x = st.top();
       //       st.pop();

       //       ans.push_back(x);
	   // }
	   // return ans;



	   // METHOD 2 (Using BFS)
	   vector<int> ans = topoSort_BFS(n, adj);
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