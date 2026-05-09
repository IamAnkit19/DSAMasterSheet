#include<bits/stdc++.h>
using namespace std;

class Solution {
    // Memoization
    bool solve(int idx, int target, vector<int> &arr, vector<vector<int>> &dp){
        if(target == 0){
            return true;
        }
        if(idx == 0){
            return arr[0] == target;
        }
        if(dp[idx][target] != -1){
            return dp[idx][target];
        }
        bool take = false;
        if(arr[idx] <= target)
            take = solve(idx-1, target-arr[idx], arr, dp);
        bool notTake = solve(idx-1, target, arr, dp);
        return take || notTake;
    }
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        // vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        // return solve(n-1, sum, arr, dp);
        
        // Tabulation
        // vector<vector<bool>> dp(n, vector<bool>(sum+1, 0));
        // for(int i=0; i<n; i++){
        //     dp[i][0] = true;
        // }
        // dp[0][arr[0]] = true;
        // for(int idx=1; idx<n; idx++){
        //     for(int target=1; target<=sum; target++){
        //         bool take = false;
        //         if(arr[idx] <= target)
        //             take = dp[idx-1][target-arr[idx]];
        //         bool notTake = dp[idx-1][target];
        //         dp[idx][target] = take || notTake;
        //     }
        // }
        // return dp[n-1][sum];
        
        // Space Optimization
        vector<bool> dp(sum+1, false), curr(sum+1, false);
        dp[0] = curr[0] = true;
        dp[arr[0]] = true;
        for(int idx=1; idx<n; idx++){
            for(int target=1; target<=sum; target++){
                bool take = false;
                if(arr[idx] <= target)
                    take = dp[target-arr[idx]];
                bool notTake = dp[target];
                curr[target] = take || notTake;
            }
            dp = curr;
        }
        return dp[sum];
    }
};