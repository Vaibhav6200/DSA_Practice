#include<bits/stdc++.h>
using namespace std;

bool isSafe(int** arr, int x, int y, int n){
    if(x < n && y < n && arr[x][y]==1)
        return true;
    return false;
}

bool rat_in_maze(int** arr, int x, int y, int n, int** solArr){
    // BASE CONDITION
    if(x==n-1 && y==n-1){
        solArr[x][y] = 1;
        return true;
    }

    if(isSafe(arr, x, y, n)){
        // Step 1: marking block as safe
        solArr[x][y] = 1;

        // checking whether we will get our solution RHS
        if(rat_in_maze(arr, x+1, y, n, solArr))
            return true;

        // checking whether we will get our solution by moving downward
        if(rat_in_maze(arr, x, y+1, n, solArr))
            return true;

        // if we do not get our solution by moving rhs or downward then we have to backtrack
        solArr[x][y]=0;     // backtracking
        return false;       // returning false because here we cannot get our solution
    }
    return false;
}

int main()
{
    int n;
    cin >> n;

// Dynamically generating 2d array
    int** arr = new int*[n];
    for(int i=0; i<n; i++)
        arr[i] = new int[n];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }


// Dynamically generating and initializing solution array
    int** solArr = new int*[n];
    for(int i=0; i<n; i++){
        solArr[i] = new int[n];
        for(int j=0; j<n; j++)
            solArr[i][j]=0;
    }

    if(rat_in_maze(arr, 0, 0, n, solArr)){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
                cout << solArr[i][j] << " ";
            cout << endl;
        }
    }

    return 0;
}



// 1 0 1 0 1
// 1 1 1 1 1
// 0 1 0 1 0
// 1 0 0 1 1
// 1 1 1 0 1