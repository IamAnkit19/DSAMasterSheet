#include<bits/stdc++.h>
using namespace std;

class Solution {
    // Memoization
    int solve(int idx, vector<int> &height, vector<int> &dp){
        if(idx == 0){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        int smallJump = solve(idx-1, height, dp) + abs(height[idx] - height[idx-1]);
        int longJump = INT_MAX;
        if(idx-2 > -1){
            longJump = solve(idx-2, height, dp) + abs(height[idx] - height[idx-2]);
        }
        return dp[idx] = min(smallJump,longJump);
    }
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        // vector<int> dp(n+1, -1);
        // return solve(n-1, height, dp);
        
        // Tabulation
        // vector<int> dp(n, -1);
        // dp[0] = 0;
        // for(int i=1; i<n; i++){
        //     int smallJump = dp[i-1] + abs(height[i] - height[i-1]);
        //     int longJump = INT_MAX;
        //     if(i-2 > -1){
        //         longJump = dp[i-2] + abs(height[i] - height[i-2]);
        //     }
        //     dp[i] = min(smallJump,longJump);
        // }
        // return dp[n-1];
        
        // Space optimization
        int prev = 0, prev2 = 0;
        for(int i=1; i<n; i++){
            int smallJump = prev + abs(height[i] - height[i-1]);
            int longJump = INT_MAX;
            if(i-2 > -1){
                longJump = prev2 + abs(height[i] - height[i-2]);
            }
            int curr = min(smallJump,longJump);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};