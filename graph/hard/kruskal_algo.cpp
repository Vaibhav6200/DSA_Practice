// Time Complexity - O(mlog(m)) {because of sorting algorithm}

#include<bits/stdc++.h>
using namespace std;


void makeSet(vector<int> &parent, vector<int> &rank, int n){
    for(int i=0; i<n; i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int> &parent, int node){
    if(parent[node] == node)
        return node;
    parent[node] = findParent(parent, parent[node]);
    return parent[node];
}

void UnionSet(int u, int v, vector<int> &parent, vector<int> &rank){
    u = findParent(parent, u);
    v = findParent(parent, v);

    if(rank[u] < rank[v])
        parent[u] = v;
    else if(rank[v] < rank[u])
        parent[v] = u;
    else{
        parent[v] = u;
        rank[u]++;
    }
}

bool compare(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);

    // sort all edges -> BASIS: wt
    sort(edges.begin(), edges.end(), compare);

    int minWeight = 0;

    // iterate over sorted edges and if u and v belong to diff components then
    // include it in MST
    for(int i=0; i<edges.size(); i++){
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int wt = edges[i][2];

        if(u != v){        // means diff. component
            minWeight += wt;
            UnionSet(u, v, parent, rank);
        }
    }

    return minWeight;
}


int main()
{

    return 0;
}