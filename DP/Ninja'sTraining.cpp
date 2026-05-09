#include<bits/stdc++.h>
using namespace std;

class Solution {
    // Memoization
    int solve(int i, int last, vector<vector<int>> &mat, vector<vector<int>> &dp){
        if(i == 0){
            int maxi = 0;
            for(int j=0; j<3; j++){
                if(j != last){
                    maxi = max(maxi, mat[i][j]);
                }
            }
            return maxi;
        }
        if(dp[i][last] != -1){
            return dp[i][last];
        }
        int maxi = 0;
        for(int j=0; j<3; j++){
            if(j != last){
                maxi = max(maxi, mat[i][j] + solve(i-1, j, mat, dp));
            }
        }
        return dp[i][last] = maxi;
    }
  public:
    int maximumPoints(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        // vector<vector<int>> dp(n, vector<int>(4, -1));
        // return solve(n-1, 3, mat, dp);
        
        // Tabulation
        // dp[0][0] = max(mat[0][1], mat[0][2]);
        // dp[0][1] = max(mat[0][0], mat[0][2]);
        // dp[0][2] = max(mat[0][0], mat[0][1]);
        // dp[0][3] = max(mat[0][0], max(mat[0][1], mat[0][2]));
        // for(int i=1; i<n; i++){
        //     for(int j=0; j<4; j++){
        //         dp[i][j] = 0;
        //         for(int k=0; k<3; k++){
        //             if(k != j){
        //                 dp[i][j] = max(dp[i][j], mat[i][k] + dp[i-1][k]);
        //             }
        //         }
        //     }
        // }
        // return dp[n-1][3];
        
        // Space Optimization
        vector<int> prev(4, 0);
        prev[0] = max(mat[0][1], mat[0][2]);
        prev[1] = max(mat[0][0], mat[0][2]);
        prev[2] = max(mat[0][0], mat[0][1]);
        prev[3] = max(mat[0][0], max(mat[0][1], mat[0][2]));
        for(int i=1; i<n; i++){
            vector<int> temp(4, 0);
            for(int j=0; j<4; j++){
                temp[j] = 0;
                for(int k=0; k<3; k++){
                    if(k != j){
                        temp[j] = max(temp[j], mat[i][k] + prev[k]);
                    }
                }
            }
            prev = temp;
        }
        return prev[3];
    }
};