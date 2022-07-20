#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

/*
    *** APPROACH (Using Backtracking) ***
1. start from 0,0
2. check if that block is safe or not
        safe means board[x][y] == word[0]
3. we will move in 4 directions (right, bottom, left, top)
    before moving to any adjacent block we will check isSafe() condition
    and will remove 1st letter of word (i.e.) word.substr(1);
*/

    bool isSafe(int x, int y, int row, int col, char ch, vector<vector<char>> &board, vector<vector<bool>> &visited){
        if(x>=0 && y>=0 && x<row && y<col && board[x][y] == ch && visited[x][y] == false)
            return true;
        return false;
    }

    // DIRECTIONS (right, bottom, left, top)
    int dirX[4] = {0, 1, 0, -1};
    int dirY[4] = {1, 0, -1, 0};

    bool solve(int x, int y, string word, vector<vector<char>> &board, vector<vector<bool>> &visited){
        int row = board.size();
        int col = board[0].size();

        if(word.length() == 0)
            return true;

        visited[x][y] = 1;

        for(int i=0; i<4; i++)
        {
            int p = x + dirX[i];
            int q = y + dirY[i];

            char ch = word[0];

            if(isSafe(p, q, row, col, ch, board, visited)){
                bool flag = solve(p, q, word.substr(1), board, visited);
                if(flag)
                    return true;
            }
        }
        visited[x][y] = 0;      // backtracking

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));

        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                if(board[i][j] == word[0])
                    if(solve(i, j, word.substr(1), board, visited))
                        return true;
        return false;
    }
};