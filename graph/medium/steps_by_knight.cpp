#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
/*
    This can be done using bfs
1. For current Node check all 8 positions that any one is target and push all in queue
2. Now check same for all its neighbours
*/

    bool isValid(int x, int y, int n, vector<vector<bool>> &visited){
        if(x>=0 && x<n && y>=0 && y<n && visited[x][y] == false)
            return true;
        return false;
    }


	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int n)
	{
	    int tx = TargetPos[0]-1;    // for 0 based indexing
	    int ty = TargetPos[1]-1;

	    int x1 = KnightPos[0]-1;    // for 0 based indexing
	    int y1 = KnightPos[1]-1;

	    // Base Case: If starting position is Target
	    if(tx == x1 && ty == y1)
	        return 0;

	    vector<vector<bool>> visited(n, vector<bool>(n, false));

	    queue<pair<int, int>> q;
	    q.push({x1, y1});
	    visited[x1][y1] = true;

	    int steps = 0;

	    while(!q.empty()){
            int size = q.size();
            steps++;

            while(size != 0){
    	        pair<int, int> p = q.front();
    	        q.pop();

    	        int u = p.first;
    	        int v = p.second;

    	        int ax[8] = {1, 1, -1, -1, 2, -2, 2, -2};
    	        int ay[8] = {2, -2, 2, -2, 1, 1, -1, -1};


    	        // checking all 8 possitions
    	        for(int i=0; i<8; i++){
    	            int xx = u + ax[i];
    	            int yy = v + ay[i];


    	            if(xx == tx && yy == ty)
    	                return steps;

    	            // check if position is valid: if Yes then push that position in queue
    	            if(isValid(xx, yy, n, visited)){
    	                visited[xx][yy] = true;
    	                q.push({xx, yy});
    	            }
    	        }
                size --;
            }
	    }

	    return steps;
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}