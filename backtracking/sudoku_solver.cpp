#include<bits/stdc++.h>
using namespace std;

/*
    *** APPROACH ***
(i) we will find first empty block
(ii) fill values from 0 to 9 in it and while doing it check if its safe or not
(iii) if safe (board[i][j] = val)
(iv) then make recursive call to solve other empty blocks
(v) then backtrack board[i][j] = 0
*/

bool isSafe(int row, int col, vector<vector<int>> board, int val){
    // checking horizontal row
    // checking vertical column
    // checking 3X3 matrix
    for(int i=0; i<9; i++){
        if(board[row][i] == val)
            return false;
        if(board[i][col] == val)
            return false;
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val)
            return false;
    }
    return true;
}

bool solve(vector<vector<int>> &board){

    int n = board[0].size();

    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){

            if(board[row][col] == 0){        // means: cell empty
                for(int val=1; val<=9; val++){
                    if(isSafe(row, col, board, val)){
                        board[row][col] = val;
                        bool solutionPossible = solve(board);
                        if(solutionPossible)
                            return true;
                        else
                            board[row][col] = 0;    // Backtracking
                    }
                }
                return false;
            }

        }
    }
    return true;
}

void solveSudoku(vector<vector<int>>& sudoku){
    solve(sudoku);
}


int main()
{

    return 0;
}