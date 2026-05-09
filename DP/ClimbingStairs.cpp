#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(int n, vector<int> &dp){
        if(dp[n] != 0){
            return dp[n];
        }
        if(n == 0 || n == 1){
            return dp[n] = 1;
        }
        return dp[n] = solve(n-1, dp) + solve(n-2, dp);
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        return solve(n, dp);
    }
};