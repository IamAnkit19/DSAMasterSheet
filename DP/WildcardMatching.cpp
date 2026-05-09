#include<bits/stdc++.h>
using namespace std;

class Solution {
    // Memoization
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        if(i == 0 && j == 0){
            return true;
        }
        if(j == 0){
            return false;
        }
        if(i == 0){
            for(int idx=1; idx<=j; idx++){
                if(p[idx-1] != '*'){
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i-1] == p[j-1] || p[j-1] == '?'){
            return dp[i][j] = solve(i-1, j-1, s, p, dp);
        }
        if(p[j-1] == '*'){
            return dp[i][j] = solve(i-1, j, s, p, dp) || solve(i, j-1, s, p, dp);
        }
        return dp[i][j] = false;
    }
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        // vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        // return solve(m, n, s, p, dp);

        // Tabulation
        // vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        // dp[0][0] = true;
        // for(int i=1; i<=m; i++){
        //     dp[i][0] = false; 
        // }
        // for(int j=1; j<=n; j++){
        //     bool flag = true;
        //     for(int idx=1; idx<=j; idx++){
        //         if(p[idx-1] != '*'){
        //             flag = false;
        //             break;
        //         }
        //     }
        //     dp[0][j] = flag;
        // }
        // for(int i=1; i<=m; i++){
        //     for(int j=1; j<=n; j++){
        //         if(s[i-1] == p[j-1] || p[j-1] == '?'){
        //             dp[i][j] = dp[i-1][j-1];
        //         }
        //         else if(p[j-1] == '*'){
        //             dp[i][j] = dp[i-1][j] || dp[i][j-1];
        //         }
        //         else{
        //             dp[i][j] = false;
        //         }
        //     }
        // }
        // return dp[m][n];

        // Space Optimization
        vector<bool> prev(n+1, false);
        prev[0] = true;
        for(int j=1; j<=n; j++){
            bool flag = true;
            for(int idx=1; idx<=j; idx++){
                if(p[idx-1] != '*'){
                    flag = false;
                    break;
                }
            }
            prev[j] = flag;
        }
        for(int i=1; i<=m; i++){
            vector<bool> curr(n+1, false);
            for(int j=1; j<=n; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    curr[j] = prev[j-1];
                }
                else if(p[j-1] == '*'){
                    curr[j] = prev[j] || curr[j-1];
                }
                else{
                    curr[j] = false;
                }
            }
            prev = curr;
        }
        return prev[n];
    }
};