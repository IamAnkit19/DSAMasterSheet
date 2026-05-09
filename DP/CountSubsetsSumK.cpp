#include<bits/stdc++.h>
using namespace std;

class Solution {
    // Memoization
    int solve(int idx, int target, vector<int> &arr, vector<vector<int>> &dp){
        if(idx == 0){
            if(target == 0 && arr[idx] == 0){
                return 2;
            }
            if(target == 0){
                return 1;
            }
            if(arr[idx] == target){
                return 1;
            }
            return 0;
        }
        if(dp[idx][target] != -1){
            return dp[idx][target];
        }
        int pick = 0;
        if(arr[idx] <= target){
            pick = solve(idx-1, target-arr[idx], arr, dp);
        }
        int notPick = solve(idx-1, target, arr, dp);
        return dp[idx][target] = pick + notPick;
    }
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        // vector<vector<int>> dp(n, vector<int>(target+1, -1));
        // return solve(n-1, target, arr, dp);
        
        // Tabulation
        // vector<vector<int>> dp(n, vector<int>(target+1, 0));
        // for(int i=0; i<n; i++){
        //     dp[i][0] = 1;
        // }
        // if(arr[0] == 0){
        //     dp[0][0] = 2;
        // }
        // else{
        //     dp[0][0] = 1;
        //     if(arr[0] <= target){
        //         dp[0][arr[0]] = 1;
        //     }
        // }
        // for(int idx=1; idx<n; idx++){
        //     for(int tar=0; tar<=target; tar++){
        //         int pick = 0;
        //         if(arr[idx] <= tar){
        //             pick = dp[idx-1][tar-arr[idx]];
        //         }
        //         int notPick = dp[idx-1][tar];
        //         dp[idx][tar] = pick + notPick;
        //     }
        // }
        // return dp[n-1][target];
        
        // Space Optimization
        vector<int> dp(target+1, 0), curr(target+1, 0);
        if(arr[0] == 0){
            dp[0] = curr[0] = 2;
        }
        else{
            dp[0] = curr[0] = 1;
            if(arr[0] <= target){
                dp[arr[0]] = 1;
            }
        }
        for(int idx=1; idx<n; idx++){
            for(int tar=0; tar<=target; tar++){
                int pick = 0;
                if(arr[idx] <= tar){
                    pick = dp[tar-arr[idx]];
                }
                int notPick = dp[tar];
                curr[tar] = pick + notPick;
            }
            dp = curr;
        }
        return dp[target];
    }
};