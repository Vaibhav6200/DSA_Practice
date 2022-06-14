#include<bits/stdc++.h>
using namespace std;


// NOTE: (x, y) represents position/block which we want to check to put our queen
bool isSafe(int **arr, int x, int y, int n){
    // Condition 1: check vertically
    for(int i=0; i<x; i++){
        if(arr[i][y]==1)
            return false;
    }

    // Condition 2: check left upper diagonal
    int row=x;
    int col=y;
    while(row>=0 && col>=0){
        if(arr[row][col]==1)
            return false;
        row--;
        col--;
    }

    // Condition 3: check right upper diagonal
    row=x;
    col=y;
    while(row>=0 && col<n){
        if(arr[row][col]==1)
            return false;
        row--;
        col++;
    }
    return true;
}

bool nQueen(int **arr, int x, int n){
    // Base Condition
    if(x>=n)
        return true;

    for(int col=0 ; col<n ; col++){
        if(isSafe(arr, x, col, n)){
            arr[x][col] = 1;

            // Checking wether we get sol for remaining rows
            if(nQueen(arr, x+1, n))
                return true;

            arr[x][col] = 0;    // if we do not get solution along a path then we do "backtracking"
        }
    }
    return false;
}

int main()
{
    int n = 4;

    int **arr = new int*[n];
    for(int i=0; i<n ; i++){
        arr[i] = new int[n];
        for(int j=0; j<n ; j++)
            arr[i][j] = 0;
    }

    if(nQueen(arr, 0, n)){
        for(int i=0; i<n ; i++){
            for(int j=0; j<n ; j++)
                cout << arr[i][j] << " ";
            cout << endl;
        }
    }

    return 0;
}