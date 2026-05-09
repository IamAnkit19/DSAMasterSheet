#include<bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution {
    // Memoization
    int solve(int idx, int n, vector<int> &price, vector<vector<int>> &dp){
        if(idx == 0){
            return n*price[0];
        }
        if(dp[idx][n] != -1){
            return dp[idx][n];
        }
        int notTake = solve(idx-1, n, price, dp);
        int take = INT_MIN;
        int rodLength = idx+1;
        if(rodLength <= n){
            take = price[idx] + solve(idx, n-rodLength, price, dp);
        }
        return dp[idx][n] = max(take, notTake);
    }
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // return solve(n-1, n, price, dp);
        
        // Tabulation
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // for(int i=0; i<=n; i++){
        //     dp[0][i] = i * price[0];
        // }
        // for(int idx=1; idx<n; idx++){
        //     for(int N=0; N<=n; N++){
        //         int notTake = dp[idx-1][N];
        //         int take = INT_MIN;
        //         int rodLength = idx+1;
        //         if(rodLength <= N){
        //             take = price[idx] + dp[idx][N-rodLength];
        //         }
        //         dp[idx][N] = max(take, notTake);
        //     }
        // }
        // return dp[n-1][n];
        
        // Space Optimization
        vector<int> dp(n+1, -1), curr(n+1, -1);
        for(int i=0; i<=n; i++){
            dp[i] = i * price[0];
        }
        for(int idx=1; idx<n; idx++){
            for(int N=0; N<=n; N++){
                int notTake = dp[N];
                int take = INT_MIN;
                int rodLength = idx+1;
                if(rodLength <= N){
                    take = price[idx] + curr[N-rodLength];
                }
                curr[N] = max(take, notTake);
            }
            dp = curr;
        }
        return dp[n];
    }
};