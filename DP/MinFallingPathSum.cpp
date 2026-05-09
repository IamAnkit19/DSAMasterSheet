#include<bits/stdc++.h>
using namespace std;

class Solution {
    // Memoization
    int solve(int i, int j, int m, int n, vector<vector<int>> &mat, vector<vector<int>> &dp){
        if(i < 0 || j < 0 || i >= m || j >= n){
            return INT_MAX;
        }
        if(i == 0){
            return mat[i][j];
        }
        if(dp[i][j] != INT_MAX){
            return dp[i][j];
        }
        return dp[i][j] = mat[i][j] + min(solve(i-1, j, m, n, mat, dp), min(solve(i-1, j-1, m, n, mat, dp), solve(i-1, j+1, m, n, mat, dp)));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        // int ans = INT_MAX;
        // vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        // for(int i=0; i<n; i++){
        //     ans = min(ans, solve(m-1, i, m, n, matrix, dp));
        // }
        // return ans;

        // Tabulation
        // vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        // for(int i=0; i<n; i++){
        //     dp[0][i] = matrix[0][i];
        // }
        // for(int i=1; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         int v = dp[i-1][j], left = INT_MAX, right = INT_MAX;
        //         if(j > 0){
        //             left = dp[i-1][j-1];
        //         }
        //         if(j < n-1){
        //             right = dp[i-1][j+1];
        //         }
        //         dp[i][j] = matrix[i][j] + min(v, min(left, right));
        //     }
        // }
        // int ans = dp[n-1][0];
        // for(int i=1; i<n; i++){
        //     ans = min(ans, dp[n-1][i]);
        // }
        // return ans;

        // Space Optimization
        vector<int> dp(n);
        for(int i=0; i<n; i++){
            dp[i] = matrix[0][i];
        }
        for(int i=1; i<m; i++){
            vector<int> temp(n);
            for(int j=0; j<n; j++){
                int v = dp[j], left = INT_MAX, right = INT_MAX;
                if(j > 0){
                    left = dp[j-1];
                }
                if(j < n-1){
                    right = dp[j+1];
                }
                temp[j] = matrix[i][j] + min(v, min(left, right));
            }
            dp = temp;
        }
        int ans = dp[0];
        for(int i=1; i<n; i++){
            ans = min(ans, dp[i]);
        }
        return ans;
    }
};