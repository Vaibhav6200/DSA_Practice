#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
/*
    *** APPROACH ***
use Union find method
1. step by step take union of those nodes who have an edge
2. if any 2 nodes are already connected (i.e) they have same parent
3. then by adding that edge we would be creating cycle so dont add it
4. push that nodes in our answer vector
*/

    int findParent(int root, vector<int> &parent){
        if(parent[root] == root)
            return root;
        parent[root] = findParent(parent[root], parent);
        return parent[root];
    }

    void Union(int u, int v, vector<int> &parent, vector<int> &rank){
        u = findParent(u, parent);
        v = findParent(v, parent);

        if(rank[u] < rank[v])
            parent[u] = v;

        else if(rank[v] < rank[u])
            parent[v] = u;

        else{
            parent[v] = u;
            rank[u]++;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);        // because nodes start from index 1
        vector<int> rank(n+1, 0);

        for(int i=0; i<=n; i++)
            parent[i] = i;

        vector<int> ans;
        for(int i=0; i<n; i++){
            int u = edges[i][0];
            int v = edges[i][1];

            int parent1 = findParent(u, parent);
            int parent2 = findParent(v, parent);
            if(parent1 == parent2){     // means u and v are already connected and this edges is redundant
                ans.push_back(u);
                ans.push_back(v);
            }
            else
                Union(u, v, parent, rank);

        }

        return ans;
    }
};