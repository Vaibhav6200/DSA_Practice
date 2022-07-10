#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

/*
    *** APPROACH ***
Using Bellman Ford algo to check for -ve edge cycle
    => relax all edges (n-1) time
after iteration for n-1 times iterate once more and if any distance gets updated
    then cycle present
    else absent
*/
	int isNegativeWeightCycle(int n, vector<vector<int>>edges)
	{
	    vector<int> dist(n+1, INT_MAX);
        dist[0] = 0;        // initializing source node

        // iterating/relaxing all edges n-1 times
        for(int i=0; i<n-1; i++){
            // traversing each edge
            for(auto edge: edges){
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];

                if(dist[u] != INT_MAX && (dist[u] + wt < dist[v]))
                    dist[v] = dist[u] + wt;
            }
        }

        bool flag = false;
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if(dist[u] != INT_MAX && (dist[u] + wt < dist[v]))
                flag = true;
        }
        return flag;
	}
};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}