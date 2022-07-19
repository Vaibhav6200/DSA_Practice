#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
/*
    *** APPROACH ***
1. In a connected component we can remove all stones except 1
2. Moves in 1 component does not affect the other component
3. Each Stone belong to exactly one component

moves_count = moves_count_group1 + moves_count_group2 + ...

moves_count = (stone_count_group1 - 1) + (stone_count_group2 - 1) + ...

moves_count = (stone_count_group1 + stone_count_group2 + ... ) - (1 + 1 + ...)

FORMULA:
moves_count = stones_count - groups_count

if 2 nodes lies in same row/column then they will be connected by an edge of graph and will belong to same component
similarly for all nodes make our graph
For a particular component (having n nodes) we can remove n-1 nodes
so Max Stones which we can pick = Total - (Remaining Nodes)
Remaining Nodes = Total no of components
*/

    void makeSet(map<pair<int, int>, int> &rank, map<pair<int, int>, pair<int, int>> &parent, vector<vector<int>> &stones){
        int n = stones.size();
        for(int i=0; i<n; i++){
            pair<int, int> p = {stones[i][0], stones[i][1]};
            parent[p] = p;
            rank[p] = 0;
        }
    }

    pair<int, int> findParent(pair<int, int> node, map<pair<int, int>, pair<int, int>> &parent){
        if(parent[node] == node)
            return node;
        parent[node] = findParent(parent[node], parent);
        return parent[node];
    }

    void Union(pair<int, int> u, pair<int, int> v, map<pair<int, int>, int> &rank, map<pair<int, int>, pair<int, int>> &parent){
        u = findParent(u, parent);
        v = findParent(v, parent);

        if(u == v)      // if both have same parent then no need to union them they already belong to same component
            return;

        if(rank[u] < rank[v])
            parent[u] = v;

        else if(rank[v] < rank[u])
            parent[v] = u;

        else{
            parent[v] = u;
            rank[u]++;
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        map<pair<int, int>, pair<int, int>> parent;
        map<pair<int, int>, int> rank;

        makeSet(rank, parent, stones);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    pair<int, int> p1 = {stones[i][0], stones[i][1]};
                    pair<int, int> p2 = {stones[j][0], stones[j][1]};
                    Union(p1, p2, rank, parent);
                }
            }
        }

        // counting the components
        int count=0;
        for(auto p: parent){
            if(p.first == p.second)
                count++;
        }

        return n-count;
    }
};


int main()
{

    return 0;
}