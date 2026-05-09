#include<bits/stdc++.h>
using namespace std;

class Solution {
    // Memoization
    int solve(string &text1, string &text2, int idx1, int idx2, vector<vector<int>> &dp){
        if(idx1 == 0 || idx2 == 0){
            return 0;
        }
        if(dp[idx1][idx2] != -1){
            return dp[idx1][idx2];
        }
        if(text1[idx1-1] == text2[idx2-1]){
            return dp[idx1][idx2] = 1 + solve(text1, text2, idx1-1, idx2-1, dp);
        }
        return dp[idx1][idx2] = max(solve(text1, text2, idx1-1, idx2, dp), solve(text1, text2, idx1, idx2-1, dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        // vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        // return solve(text1, text2, n1, n2, dp);

        // Tabulation
        // vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        // for(int i=0; i<=n1; i++){
        //     dp[i][0] = 0;
        // }
        
        // for(int i=0; i<=n2; i++){
        //     dp[0][i] = 0;
        // }
        // for(int idx1=1; idx1<=n1; idx1++){
        //     for(int idx2=1; idx2<=n2; idx2++){
        //         if(text1[idx1-1] == text2[idx2-1]){
        //             dp[idx1][idx2] = 1 + dp[idx1-1][idx2-1];
        //         }
        //         else{
        //             dp[idx1][idx2] = max(dp[idx1-1][idx2], dp[idx1][idx2-1]);
        //         }
        //     }
        // }
        // return dp[n1][n2];

        // Space optimization
        vector<int> dp(n2+1, 0), curr(n2+1, 0);        
        for(int i=0; i<=n2; i++){
            dp[i] = 0;
        }
        for(int idx1=1; idx1<=n1; idx1++){
            for(int idx2=1; idx2<=n2; idx2++){
                if(text1[idx1-1] == text2[idx2-1]){
                    curr[idx2] = 1 + dp[idx2-1];
                }
                else{
                    curr[idx2] = max(dp[idx2], curr[idx2-1]);
                }
            }
            dp = curr;
        }
        return dp[n2];
    }
};