#include<bits/stdc++.h>
using namespace std;

class Solution {
    // Memoization
    int solve(int i, int j, int m, vector<vector<int>> &triangle, vector<vector<int>> &dp){
        if(i >= m){
            return 0;
        }
        int n = triangle[i].size();
        if(j < 0 || j >= n){
            return 0;
        }
        if(i == m-1){
            return triangle[i][j];
        }
        if(dp[i][j] != INT_MAX){
            return dp[i][j];
        }
        return dp[i][j] = triangle[i][j] + min(solve(i+1, j, m, triangle, dp), solve(i+1, j+1, m, triangle, dp));
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size(), n = triangle[m-1].size();
        // vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        // return solve(0, 0, m, triangle, dp);

        // Tabulation
        // for(int i=0; i<n; i++){
        //     dp[m-1][i] = triangle[m-1][i];
        // }
        // for(int i=n-2; i>=0; i--){
        //     for(int j=i; j>=0; j--){
        //         int x1 = triangle[i][j] + dp[i+1][j];
        //         int x2 = triangle[i][j] + dp[i+1][j+1];
        //         dp[i][j] = min(x1, x2);
        //     }
        // }
        // return dp[0][0];

        // Space Optimization
        vector<int> dp(n, INT_MAX);
        for(int i=0; i<n; i++){
            dp[i] = triangle[m-1][i];
        }
        for(int i=n-2; i>=0; i--){
            vector<int> temp(n);
            for(int j=i; j>=0; j--){
                int x1 = triangle[i][j] + dp[j];
                int x2 = triangle[i][j] + dp[j+1];
                temp[j] = min(x1, x2);
            }
            dp = temp;
        }
        return dp[0];
    }
};