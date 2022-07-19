#include <bits/stdc++.h>
using namespace std;


// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.

bool possible(int node, int col, unordered_map<int, list<int>> &adj, vector<int> &colorArr){
    for(auto nbr: adj[node])
        if(col == colorArr[nbr])
            return false;
    return true;
}

bool dfs(int node, int N, vector<int> &colorArr, vector<int> colors,
        unordered_map<int, list<int>> &adj, vector<int> &visited){

    if(node == N)
        return true;

    for(auto col: colors){
        if(possible(node, col, adj, colorArr)){
            colorArr[node] = col;

            bool flag = dfs(node+1, N, colorArr, colors, adj, visited);
            if(flag == true)
                return true;

            colorArr[node] = 0;     // backtracking
        }
    }

    return false;
}

// void printList(unordered_map<int, list<int>> &adj){
//     for(auto i: adj){
//         cout << i.first << " -> ";
//         for(auto j: i.second)
//             cout << j << " ";
//         cout << endl;
//     }
// }

bool graphColoring(bool graph[101][101], int m, int n) {

    vector<int> visited(n, 0);
    vector<int> colorArr(n, -1);
    vector<int> colors(m);


    // create adjList
    unordered_map<int, list<int>> adj;

    for(int i=0; i<101; i++)
        for(int j=0; j<101; j++)
            if(graph[i][j] == true)
                adj[i].push_back(j);


    // initiallizing colors array
    for(int i=0; i<m; i++)
        colors[i] = i;

    for(int i=0; i<n; i++)
        if(!visited[i]){
            colorArr[i] = 0;
            bool flag = dfs(i, n, colorArr, colors, adj, visited);
            if(flag)
                return true;
        }

    return false;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}