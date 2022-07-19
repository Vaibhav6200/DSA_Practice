#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
/*
    *** APPROACH (Using BFS) ***
step1: push all position with 2 in queue
step2: now while queue is not empty, take out element from queue and check its all 4 directions
        if its Safe with value == 1 then mark them as rotten (2)
        and push them in queue
*/
    bool isSafe(int x, int y, int row, int col, vector<vector<int>> &grid){
        if(x>=0 && y>=0 && x<row && y<col and grid[x][y] == 1)
            return true;
        return false;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int, int>> q;

        // push all rotten eggs in queue
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                if(grid[i][j] == 2)
                    q.push({i, j});

        int minTime = -1;
        while(!q.empty()){
            // traversing each level and if oranges found then make them rotten and push in queue
            int size = q.size();
            minTime++;
            while(size != 0){
                auto temp = q.front();
                q.pop();

                int i = temp.first;
                int j = temp.second;

                // check all 4 directions
                int dirX[4] = {0, 1, 0, -1};
                int dirY[4] = {1, 0, -1, 0};

                for(int k=0; k<4; k++){
                    int x = i + dirX[k];
                    int y = j + dirY[k];

                    if(isSafe(x, y, row, col, grid)){
                        grid[x][y] = 2;
                        q.push({x, y});
                    }
                }

                size--;
            }
        }

        if(minTime == 0)
            return -1;

        // if any 1 orange is not yet rotten means we cannot reach it so return -1
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                if(grid[i][j] == 1)
                    return -1;

        return minTime;
    }
};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}