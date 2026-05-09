#include<bits/stdc++.h>
using namespace std;

class Solution {
    // Memoization
    int solve(int i, int j1, int j2, int m, int n, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){
        if(j1 < 0 || j1 >= n || j2 < 0 || j2 >= n){
            return -1e8;
        }
        if(i == m-1){
            if(j1 != j2){
                return grid[i][j1] + grid[i][j2];
            }
            else{
                return grid[i][j1];
            }
        }
        if(dp[i][j1][j2] != -1){
            return dp[i][j1][j2];
        }
        int maxi = -1e8;
        for(int it=-1; it<=1; it++){
            for(int jt=-1; jt<=1; jt++){
                int value = 0;
                if(j1 == j2){
                    value = grid[i][j1];
                }
                else{
                    value = grid[i][j1] + grid[i][j2];
                }
                maxi = max(maxi, value + solve(i+1, j1+it, j2+jt, m, n, grid, dp));
            }
        }
        return dp[i][j1][j2] = maxi;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        // return solve(0, 0, n-1, m, n, grid, dp);

        // Tabulation
        // vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         if(i == j){
        //             dp[m-1][i][j] = grid[m-1][j];
        //         }
        //         else{
        //             dp[m-1][i][j] = grid[m-1][i] + grid[m-1][j];
        //         }
        //     }
        // }
        // for(int i=m-2; i>=0; i--){
        //     for(int j1=0; j1<n; j1++){
        //         for(int j2=0; j2<n; j2++){
        //             int maxi = -1e8;
        //             for(int it=-1; it<=1; it++){
        //                 for(int jt=-1; jt<=1; jt++){
        //                     int value = 0;
        //                     if(j1 == j2){
        //                         value = grid[i][j1];
        //                     }
        //                     else{
        //                         value = grid[i][j1] + grid[i][j2];
        //                     }
        //                     if(j1+it >= 0 && j1+it < n && j2+jt >= 0 && j2+jt < n){
        //                         value += dp[i+1][j1+it][j2+jt];
        //                     }
        //                     else{
        //                         value += -1e8;
        //                     }
        //                     maxi = max(maxi, value);
        //                 }
        //             }
        //             dp[i][j1][j2] = maxi;
        //         }
        //     }
        // }
        // return dp[0][0][n-1];

        // Space Optimization
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j){
                    dp[i][j] = grid[m-1][j];
                }
                else{
                    dp[i][j] = grid[m-1][i] + grid[m-1][j];
                }
            }
        }
        for(int i=m-2; i>=0; i--){
            vector<vector<int>> temp(n, vector<int>(n));
            for(int j1=0; j1<n; j1++){
                for(int j2=0; j2<n; j2++){
                    int maxi = -1e8;
                    for(int it=-1; it<=1; it++){
                        for(int jt=-1; jt<=1; jt++){
                            int value = 0;
                            if(j1 == j2){
                                value = grid[i][j1];
                            }
                            else{
                                value = grid[i][j1] + grid[i][j2];
                            }
                            if(j1+it >= 0 && j1+it < n && j2+jt >= 0 && j2+jt < n){
                                value += dp[j1+it][j2+jt];
                            }
                            else{
                                value += -1e8;
                            }
                            maxi = max(maxi, value);
                        }
                    }
                    temp[j1][j2] = maxi;
                }
            }
            dp = temp;
        }
        return dp[0][n-1];
    }
};