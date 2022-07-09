#include<bits/stdc++.h>
using namespace std;


/*
    *** APPROACH ***
1.  First find topological order  (using it we can know whether we can reach destination or not)
2.  make dist array and set dist[src] = 0;
*/

// Directed graph
class Graph{
    public:

    unordered_map<int, list<pair<int, int>> > adj;
    void insertion(int u, int v, int weight){
        adj[u].push_back({v, weight});
    }

    void print(){
        for(auto i: adj){
            cout << i.first << " -> ";
            for(auto j: i.second)
                cout << "[" << j.first << ", " << j.second << "] ";
            cout << endl;
        }
    }


    void DFS(int node, vector<int> &visited, stack<int> &st)
    {
        visited[node] = 1;
        for(auto neighbour: adj[node])
        {
            if(!visited[neighbour.first])
                DFS(neighbour.first, visited, st);
        }
        st.push(node);
    }
    stack<int> topological_sort(int e){
        stack<int> st;
        vector<int> visited(e);

        // handling non connected components case
        for(int i=0; i<e; i++){
            if(!visited[i])
                DFS(i, visited, st);
        }

        return st;
    }


    vector<int> shortestPath(int src, int v, int e){

        // Step1 : find topological sort
        stack<int> st = topological_sort(e);

        // Step2: make Dist array and initialize all values with infinity
        vector<int> dist(v);
        for(int i=0; i<v; i++)
            dist[i] = INT_MAX;

        // Step3: Now set dist of src node
        dist[src] = 0;
        while(st.top() != src)
            st.pop();

        while(!st.empty()){
            int front = st.top();
            st.pop();

            // update neighbour vertices (Relaxing vertices)
            for(auto i: adj[front])
                if(dist[front] + i.second < dist[i.first])     // condition for relaxation of nodes
                    dist[i.first] = dist[front] + i.second;
        }

        return dist;
    }
};




int main()
{
    Graph g;
    int v = 6;
    int e = 9;
    g.insertion(0, 1, 5);
    g.insertion(0, 2, 3);
    g.insertion(1, 3, 6);
    g.insertion(1, 2, 2);
    g.insertion(2, 3, 7);
    g.insertion(2, 4, 4);
    g.insertion(2, 5, 2);
    g.insertion(3, 4, -1);
    g.insertion(4, 5, -2);

    // g.print();

    int src = 1;
    vector<int> ans = g.shortestPath(src, v, e);
    for(int i=0; i<ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}