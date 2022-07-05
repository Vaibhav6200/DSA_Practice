#include<bits/stdc++.h>
using namespace std;


// adds and edge between node u and v
void addEdge(int u, int v, vector<int> adj[]){
    adj[u].push_back(v);
    adj[v].push_back(u);
}


void printGraph(int n, vector<int> adj[]){
    for(int i=0; i<n; i++)
    {
        int n = adj[i].size();
        cout << i << " -> ";

        for(int j=0; j<n; j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter no of nodes: ";
    cin >> n;

    vector<int> adj[n];

    addEdge(0, 1, adj);
    addEdge(0, 2, adj);
    addEdge(1, 3, adj);
    addEdge(3, 4, adj);
    addEdge(3, 5, adj);

    printGraph(n, adj);

    return 0;
}