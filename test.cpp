#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> straightArray(vector<vector<int>> &board){
        vector<int> result;
        int n = board.size();

        result.push_back(INT_MAX);      // starting position is occupied by Infinity for 1-based indexing

        bool flag = true;
        for(int i=n-1; i>=0; i--){
            if(flag){
                for(int j=0; j<n; j++){
                    int x = board[i][j];
                    result.push_back(x);
                }
            }
            else{
                for(int j=n-1; j>=0; j--){
                    int x = board[i][j];
                    result.push_back(x);
                }
            }

            flag = !flag;
        }

        return result;
    }

    int snakesAndLadders(vector<vector<int>>& matrix)
    {
        // straighten our 2d board
        vector<int> board = straightArray(matrix);
        int N = board.size();
        vector<bool> visited(N, false);

        for(auto i: board)
            cout << i << " ";

        queue<int> q;           // pair = {index, cost}
        q.push(1);              // pushing initial position and cost
        visited[1] = true;      // mark initial node as visited

        int steps = 0;
        while(!q.empty()){
            int size = q.size();
            steps++;
            while(size != 0){
                int idx = q.front();
                q.pop();

                // check all 6 positions
                for(long v=idx+1; v<=idx+6 && v<N; v++){

                    if((board[v] == -1 && v == N-1) || (board[v] == N-1))
                        return steps;

                    if(!visited[v]){
                        if(board[v] != -1){
                            visited[board[v]] = true;
                            q.push(board[v]);
                        }
                        else{
                            visited[v] = true;
                            q.push(v);
                        }
                    }
                }

                size--;

            }
        }


        return -1;
    }
};

int main()
{

    return 0;
}