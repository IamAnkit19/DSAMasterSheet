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
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        string s2 = s;
        reverse(s2.begin(), s2.end());
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return solve(s, s2, n, n, dp);

        // Tabulation
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // for(int i=0; i<=n; i++){
        //     dp[i][0] = 0;
        // }
        
        // for(int i=0; i<=n; i++){
        //     dp[0][i] = 0;
        // }
        // for(int idx1=1; idx1<=n; idx1++){
        //     for(int idx2=1; idx2<=n; idx2++){
        //         if(s[idx1-1] == s2[idx2-1]){
        //             dp[idx1][idx2] = 1 + dp[idx1-1][idx2-1];
        //         }
        //         else{
        //             dp[idx1][idx2] = max(dp[idx1-1][idx2], dp[idx1][idx2-1]);
        //         }
        //     }
        // }
        // return dp[n][n];

        // Space optimization
        vector<int> dp(n+1, 0), curr(n+1, 0);        
        for(int i=0; i<=n; i++){
            dp[i] = 0;
        }
        for(int idx1=1; idx1<=n; idx1++){
            for(int idx2=1; idx2<=n; idx2++){
                if(s[idx1-1] == s2[idx2-1]){
                    curr[idx2] = 1 + dp[idx2-1];
                }
                else{
                    curr[idx2] = max(dp[idx2], curr[idx2-1]);
                }
            }
            dp = curr;
        }
        return dp[n];
    }
};