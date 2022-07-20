#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

// APPROACH 4 => Space Optimization for Tabulation method
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        int prev1 = cost[1];
        int prev2 = cost[0];

        for(int i=2; i<n; i++){
            int curr = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return min(prev1, prev2);
    }


// APPROACH 3 Tabulation Method (Using bottom-up approach dp)

//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();

//         // Step1: create DP array
//         vector<int> dp(n+1);

//         // Step2: base case analyse and initiallize dp array
//         dp[0] = cost[0];
//         dp[1] = cost[1];

//         // Step3: Apply For Loop
//         for(int i=2; i<n; i++){     // applying loop till (n-1)th element because we have to add cost's only upto n-1th element
//             dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
//         }

//         return min(dp[n-1], dp[n-2]);
//     }


/*
    *** APPROACH 2 (Using Top-down approach dp) ***
    Using DP to optimise recursive approach
Step1: Declare dp array
Step2: store result in dp array and return dp[n]
Step3: Write additional condition below base case
        if(dp[n] != -1)
            return dp[n];
*/

//     int solve(int n, vector<int> &cost, vector<int> &dp){
//         if(n == 0 || n == 1)
//             return cost[n];
//         if(n < 0)
//             return 0;

//         // Step3
//         if(dp[n] != -1)
//             return dp[n];

//         // Step2
//         dp[n] = cost[n] + min(solve(n-1, cost, dp), solve(n-2, cost, dp));
//         return dp[n];
//     }

//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();

//         // Step1
//         vector<int> dp(n+1, -1);
//         return min(solve(n-1, cost, dp), solve(n-2, cost, dp));
//     }



/*
    *** APPROACH 1 ***
if we are at nth position then

*/
//     int solve(int n, vector<int> &cost){
//         if(n == 0 || n == 1)
//             return cost[n];
//         if(n < 0)
//             return 0;
//         return cost[n] + min(solve(n-1, cost), solve(n-2, cost));
//     }

//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         return min(solve(n-1, cost), solve(n-2, cost));
//     }
};