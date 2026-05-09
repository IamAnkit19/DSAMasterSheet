#include<bits/stdc++.h>
using namespace std;

class Solution {
    // Memoization
    int solve(int idx, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp){
        if(W <= 0){
            return 0;
        }
        if(idx == 0){
            if(wt[idx] <= W){
                return val[idx];
            }
            else{
                return 0;
            }
        }
        if(dp[idx][W] != -1){
            return dp[idx][W];
        }
        int pick = 0;
        if(wt[idx] <= W){
            pick = val[idx] + solve(idx-1, W-wt[idx], val, wt, dp);
        }
        int notPick = solve(idx-1, W, val, wt, dp);
        return dp[idx][W] = max(pick, notPick);
    }
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        // vector<vector<int>> dp(n, vector<int>(W+1, -1));
        // return solve(n-1, W, val, wt, dp);
        
        // Tabulation
        // vector<vector<int>> dp(n, vector<int>(W+1, 0));
        // for(int w=0; w<=W; w++){
        //     if(wt[0] <= w)
        //         dp[0][w] = val[0];
        // }
        // for(int idx=1; idx<n; idx++){
        //     for(int w=0; w<=W; w++){
        //         int pick = 0;
        //         if(wt[idx] <= w){
        //             pick = val[idx] + dp[idx-1][w-wt[idx]];
        //         }
        //         int notPick = dp[idx-1][w];
        //         dp[idx][w] = max(pick, notPick);
        //     }
        // }
        // return dp[n-1][W];
        
        // Space Optimization
        vector<int> dp(W+1, 0), curr(W+1, 0);
        for(int w=0; w<=W; w++){
            if(wt[0] <= w)
                dp[w] = val[0];
        }
        for(int idx=1; idx<n; idx++){
            for(int w=0; w<=W; w++){
                int pick = 0;
                if(wt[idx] <= w){
                    pick = val[idx] + dp[w-wt[idx]];
                }
                int notPick = dp[w];
               curr[w] = max(pick, notPick);
            }
            dp = curr;
        }
        return dp[W];
    }
};