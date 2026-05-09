#include<bits/stdc++.h>
using namespace std;

// I
class Solution {
    // Memoization
    int solve(int m, int n, vector<vector<int>> &dp){
        if(m <= 0 || n <= 0){
            return 0;
        }
        if(dp[m][n] != 0){
            return dp[m][n];
        }
        return dp[m][n] = 1 + solve(m-1, n, dp) + solve(m, n-1, dp);
    }
public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m, vector<int>(n, 0));
        // return 1 + solve(m-1, n-1, dp);

        // Tabulation
        // dp[0][0] = 1;
        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         if(i == 0 && j == 0){
        //             dp[0][0] = 1;
        //         }
        //         else{
        //             int up = 0, left = 0;
        //             if(i > 0){
        //                 up = dp[i-1][j];
        //             }
        //             if(j > 0){
        //                 left = dp[i][j-1];
        //             }
        //             dp[i][j] = up + left;
        //         }
        //     }
        // }
        // return dp[m-1][n-1];

        // Space Optimization
        vector<int> dp(n, 1);
        for(int i=1; i<m; i++){
            for(int j=0; j<n; j++){
                int up = dp[j], left = 0;
                if(j > 0){
                    left = dp[j-1];
                }
                dp[j] = up + left;
            }
        }
        return dp[n-1];
    }
};

// II
class Solution {
    // Memoization
    int solve(int m, int n, vector<vector<int>> &obst, vector<vector<int>> &dp){
        if(m < 0 || n < 0 || obst[m][n] == 1){
            return 0;
        }
        if(m == 0 && n == 0){
            return 1;
        }
        if(dp[m][n] != 0){
            return dp[m][n];
        }
        int up = solve(m-1, n, obst, dp);
        int left = solve(m, n-1, obst, dp);
        return up + left;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        // vector<vector<int>> dp(m, vector<int>(n, 0));
        // return solve(m-1, n-1, obstacleGrid, dp);

        // Tabulation
        // for(int i=0; i<m; i++){
        //     for(int j=0; j<n; j++){
        //         if(obstacleGrid[i][j] == 1){
        //             dp[i][j] = 0;
        //         }
        //         else if(i == 0 && j == 0){
        //             dp[i][j] = 1;
        //         }
        //         else{
        //             int up = 0, left = 0;
        //             if(i > 0){
        //                 up = dp[i-1][j];
        //             }
        //             if(j > 0){
        //                 left = dp[i][j-1];
        //             }
        //             dp[i][j] = up + left;
        //         }
        //     }
        // }
        // return dp[m-1][n-1];

        // Space Optimization
        vector<int> dp(n, 0);
        for(int i=0; i<n; i++){
            if(obstacleGrid[0][i] == 1){
                break;
            }
            else{
                dp[i] = 1;
            }
        }
        for(int i=1; i<m; i++){
            for(int j=0; j<n; j++){
                if(obstacleGrid[i][j] == 1){
                    dp[j] = 0;
                }
                else{
                    int up = 0, left = 0;
                    if(i > 0){
                        up = dp[j];
                    }
                    if(j > 0){
                        left = dp[j-1];
                    }
                    dp[j] = up + left;
                }
            }
        }
        return dp[n-1];
    }
};