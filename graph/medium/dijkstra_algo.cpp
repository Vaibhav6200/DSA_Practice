#include<bits/stdc++.h>
using namespace std;


/*
    *** APPROACH ***

*/

class compare{
    public:
    bool operator()(pair<int, int> a, pair<int, int> b){    // pair{node, wt}: Compare based on weight
        return a.second > b.second;
    }
};

vector<int> dijkstra(vector<vector<int>> &vec, int v, int edges, int src) {

    // creating adj list
    unordered_map<int, list<pair<int, int>> > adj;
    for(int i=0; i<edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int wt = vec[i][2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    // create required datastructures
    vector<int> dist(v, INT_MAX);
    vector<int> mst(v, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> minHeap;

    // initializing source node
    minHeap.push({src, 0});
    dist[src] = 0;

    while(!minHeap.empty()){
        pair<int, int> p = minHeap.top();
        minHeap.pop();

        // include our node in MST
        int u = p.first;
        mst[u] = 1;

        // explore its adj nodes
        for(auto nbr: adj[u]){
            // relax nbr nodes
            int v = nbr.first;
            int wt = nbr.second;
            if(dist[u] + wt < dist[v])
                dist[v] = dist[u] + wt;

            // push nbr nodes in minHeap if not already included
            if(mst[v] == 0)
                minHeap.push({v, wt});
        }
    }

    return dist;
}


int main()
{

    return 0;
}
