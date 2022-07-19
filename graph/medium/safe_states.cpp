#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

/*
    *** Approach 2 ***
    All nodes which are not in cycle are our answer
*/

    bool dfs(int node, unordered_map<int, list<int>> &adj, vector<bool> &visited, vector<bool> &dfsVisited, vector<bool> &present_cycle){
        visited[node] = true;
        dfsVisited[node] = true;

        for(auto nbr: adj[node]){
            if(!visited[nbr]){
                if(dfs(nbr, adj, visited, dfsVisited, present_cycle)){
                    present_cycle[node] = true;
                    return true;
                }
            }
            else if(dfsVisited[nbr]){      // cycle detected
                present_cycle[node] = true;
                return true;
            }
        }

        dfsVisited[node] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        unordered_map<int, list<int>> adj;
        for(int i=0; i<n; i++)
           for(auto j: graph[i])
               adj[i].push_back(j);


        // detect cycle nodes
        vector<bool> visited(n, false);
        vector<bool> dfsVisited(n, false);
        vector<bool> present_cycle(n, false);

        for(int i=0; i<n; i++)
            if(!visited[i])
                dfs(i, adj, visited, dfsVisited, present_cycle);


        vector<int> ans;
        for(int i=0; i<n; i++)
            if(!present_cycle[i])
                ans.push_back(i);

        return ans;
    }

/*
    *** Approach 1 (this does not include cycle case)***

1. Find all Terminal Nodes
2. Now for a nodes check that whether all its neighbour nodes end at a Terminal node (recursively)
    if(yes)
        => then include it in our answer vector
3. Repeat step2 for all nodes
*/
//     bool match(int x, vector<int> &terminal){
//         for(auto i: terminal)
//             if(x == i)
//                 return true;
//         return false;
//     }


//     // check whether node neighbour ends at a terminal node or not
//     bool dfs(int node, unordered_map<int, list<int>> &adj, vector<int> &vis, vector<int> &terminal){

//         // check if curr node is terminal
//         if(match(node, terminal))
//             return true;

//         vis[node] = 1;

//         for(auto nbr: adj[node])
//             if(!vis[nbr]){
//                 if(dfs(nbr, adj, vis, terminal))
//                    return true;
//             }

//         return false;
//     }

//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         vector<int> ans;
//         int n = graph.size();
//         vector<bool> visited(n, false);

//         // Step1: create adj list
//         unordered_map<int, list<int>> adj;
//         for(int i=0; i<n; i++){
//             for(auto j: graph[i]){
//                 int u = i;
//                 int v = j;

//                 adj[u].push_back(v);
//             }
//         }

//         // Step2: find all terminal Nodes
//         vector<int> terminal;
//         for(int i=0; i<n; i++)
//             if(graph[i].size() == 0){
//                 visited[i] = true;
//                 terminal.push_back(i);
//             }

//         // Step3: add all terminal nodes in our answer
//         for(auto i: terminal)
//             ans.push_back(i);


//         // Step4: for each node check if all its neighbours ends at a terminal nodes or not
//         for(int i=0; i<n; i++){
//             vector<int> vis(n, 0);

//             if(graph[i].size()>0){
//                 bool flag = true;
//                 for(auto nbr: adj[i]){
//                     if(!dfs(i, adj, vis, terminal))
//                         flag = false;
//                 }
//                 if(flag)
//                     ans.push_back(i);
//             }
//         }

//         // Step5: Sort Resultant array
//         sort(ans.begin(), ans.end());

//         return ans;
//     }
};