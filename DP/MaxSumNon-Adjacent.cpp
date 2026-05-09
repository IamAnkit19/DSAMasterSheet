#include<bits/stdc++.h>
using namespace std;

// User function template for C++
class Solution {
    // Memoization
    int solve(int idx, vector<int> &arr, vector<int> &dp){
        if(idx < 0){
            return 0;
        }
        if(idx == 0){
            return arr[0];
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        int take = arr[idx] + solve(idx-2, arr, dp);
        int notTake = solve(idx-1, arr, dp);
        return dp[idx] = max(take, notTake);
    }
  public:
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> dp(n, -1);
        // return solve(n-1, arr, dp);
        
        // Tabulation
        // dp[0] = arr[0];
        // for(int i=1; i<n; i++){
        //     int take = arr[i];
        //     if(i > 1){
        //         take += dp[i-2];
        //     }
        //     int notTake = dp[i-1];
        //     dp[i] = max(take, notTake);
        // }
        // return dp[n-1];
        
        // Space Optimization
        int prev = arr[0];
        int prev2 = 0;
        for(int i=1; i<n; i++){
            int take = arr[i] + prev2;
            int notTake = prev;
            int curr = max(take, notTake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};