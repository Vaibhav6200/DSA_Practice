#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

/*
    0,1,0
    0,0,0
    0,0,1

    1,1,1,1,1
    1,0,0,0,1
    1,0,1,0,1
    1,0,0,0,1
    1,1,1,1,1

    *** APPROACH ***
This is a shortest distance problem
we have to find shortest path from 1 island to another

1. Find first island and mark all its one's visited using DFS and push all of them in queue
2. Now take element from queue and check all its four directions
    if nbr is not visited and their value == 1 then we found our 2nd island so return our steps
    if nbr is not visited and their value == 0 then push them in queue
*/

    void dfs(int x, int y, int n, vector<vector<int>> &grid, vector<vector<int>> &visited, queue<pair<int, int>> &q){
        if(x<0 || x>=n || y<0 || y>=n || grid[x][y] == 0 || visited[x][y] == 1)
            return;

        visited[x][y] = 1;
        q.push({x, y});

        dfs(x, y+1, n, grid, visited, q);     // right
        dfs(x+1, y, n, grid, visited, q);     // down
        dfs(x, y-1, n, grid, visited, q);     // left
        dfs(x-1, y, n, grid, visited, q);     // Up
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        queue<pair<int, int>> q;

        // Step1: Find First Island and mark complete island as visited
        bool flag = true;
        for(int i=0 ; i<n && flag ; i++){
            for(int j=0 ; j<n && flag ; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    dfs(i, j, n, grid, visited, q);
                    flag = false;
                }
            }
        }

        // Step2: Find Shortest distance from 1 island to another using BFS
        int steps=0;
        while(!q.empty()){
            int size = q.size();
            steps++;
            while(size != 0){
                pair<int, int> p = q.front();
                q.pop();

                int x = p.first;
                int y = p.second;

                // check all 4 directions (right, down, left, top)
                pair<int, int> dir[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
                for(int i=0; i<4; i++){
                    pair<int, int> temp = dir[i];

                    int xx = x + temp.first;
                    int yy = y + temp.second;

                    // checking if neighbouring indices are vaild or not
                    if(xx>=0 && xx<n && yy>=0 && yy<n){
                        if(!visited[xx][yy] && grid[xx][yy] == 1)
                            return steps-1;

                        if(!visited[xx][yy] && grid[xx][yy] == 0){
                            visited[xx][yy] = 1;
                            q.push({xx, yy});
                        }
                    }
                }

                size--;
            }
        }



        return 0;
    }
};


int main()
{

    return 0;
}
