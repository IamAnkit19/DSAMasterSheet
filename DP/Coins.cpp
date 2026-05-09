#include<bits/stdc++.h>
using namespace std;

class Solution {
    // Memoization
    int solve(int idx, int amount, vector<int> &coins, vector<vector<int>> &dp){
        if(idx == 0){
            if(amount % coins[idx] == 0){
                return amount / coins[idx];
            }
            return 1e9;
        }
        if(dp[idx][amount] != -1){
            return dp[idx][amount];
        }
        int take = 1e9;
        if(coins[idx] <= amount){
            take = 1 + solve(idx, amount-coins[idx], coins, dp);
        }
        int notTake = solve(idx-1, amount, coins, dp);
        return dp[idx][amount] = min(take, notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        // int ans = solve(n-1, amount, coins, dp);
        // return ans == 1e9 ? -1 : ans;

        // Tabulation
        // vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        // for(int i=0; i<=amount; i++){
        //     if(i % coins[0] == 0){
        //         dp[0][i] = i / coins[0];
        //     }
        //     else{
        //         dp[0][i] = 1e9;
        //     }
        // }
        // for(int idx=1; idx<n; idx++){
        //     for(int amt=0; amt<=amount; amt++){
        //         int take = 1e9;
        //         if(coins[idx] <= amt){
        //             take = 1 + dp[idx][amt-coins[idx]];
        //         }
        //         int notTake = dp[idx-1][amt];
        //         dp[idx][amt] = min(take, notTake);
        //     }
        // }
        // return dp[n-1][amount] == 1e9 ? -1 : dp[n-1][amount];

        // Space Optimization
        vector<int> dp(amount+1, 0), curr(amount+1, 0);
        for(int i=0; i<=amount; i++){
            if(i % coins[0] == 0){
                dp[i] = i / coins[0];
            }
            else{
                dp[i] = 1e9;
            }
        }
        for(int idx=1; idx<n; idx++){
            for(int amt=0; amt<=amount; amt++){
                int take = 1e9;
                if(coins[idx] <= amt){
                    take = 1 + curr[amt-coins[idx]];
                }
                int notTake = dp[amt];
                curr[amt] = min(take, notTake);
            }
            dp = curr;
        }
        return dp[amount] == 1e9 ? -1 : dp[amount];
    }
};