#include<bits/stdc++.h>
using namespace std;

class Solution {
    // Memoization
    // int solve(int idx1, int idx2, string &s1, string &s2, vector<vector<int>> &dp){
    //     if(idx1 < 0){
    //         return idx2+1;
    //     }
    //     if(idx2 < 0){
    //         return idx1+1;
    //     }
    //     if(dp[idx1][idx2] != -1){
    //         return dp[idx1][idx2];
    //     }
    //     if(s1[idx1] == s2[idx2]){
    //         return dp[idx1][idx2] = solve(idx1-1, idx2-1, s1, s2, dp);
    //     }
    //     int insert = 1 + solve(idx1, idx2-1, s1, s2, dp);
    //     int del = 1 + solve(idx1-1, idx2, s1, s2, dp);
    //     int replace = 1 + solve(idx1-1, idx2-1, s1, s2, dp);
    //     return dp[idx1][idx2] = min(insert, min(del, replace));
    // }
    int solve(int idx1, int idx2, string &s1, string &s2, vector<vector<int>> &dp){
        if(idx1 == 0){
            return idx2;
        }
        if(idx2 == 0){
            return idx1;
        }
        if(dp[idx1][idx2] != -1){
            return dp[idx1][idx2];
        }
        if(s1[idx1-1] == s2[idx2-1]){
            return dp[idx1][idx2] = solve(idx1-1, idx2-1, s1, s2, dp);
        }
        int insert = 1 + solve(idx1, idx2-1, s1, s2, dp);
        int del = 1 + solve(idx1-1, idx2, s1, s2, dp);
        int replace = 1 + solve(idx1-1, idx2-1, s1, s2, dp);
        return dp[idx1][idx2] = min(insert, min(del, replace));
    }
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        // vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        // return solve(n1, n2, word1, word2, dp);

        // Tabulation
        // vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        // for(int i=0; i<=n1; i++){
        //     dp[i][0] = i;
        // }
        // for(int i=0; i<=n2; i++){
        //     dp[0][i] = i;
        // }
        // for(int idx1=1; idx1<=n1; idx1++){
        //     for(int idx2=1; idx2<=n2; idx2++){
        //         if(word1[idx1-1] == word2[idx2-1]){
        //             dp[idx1][idx2] = dp[idx1-1][idx2-1];
        //         }
        //         else{
        //             int insert = 1 + dp[idx1][idx2-1];
        //             int del = 1 + dp[idx1-1][idx2];
        //             int replace = 1 + dp[idx1-1][idx2-1];
        //             dp[idx1][idx2] = min(insert, min(del, replace));
        //         }
        //     }
        // }
        // return dp[n1][n2];

        // Space Optimization
        vector<int> dp(n2+1, 0), curr(n2+1, 0);
        for(int i=0; i<=n2; i++){
            dp[i] = i;
        }
        for(int idx1=1; idx1<=n1; idx1++){
            curr[0] = idx1;
            for(int idx2=1; idx2<=n2; idx2++){
                if(word1[idx1-1] == word2[idx2-1]){
                    curr[idx2] = dp[idx2-1];
                }
                else{
                    curr[idx2] = 1 + min(dp[idx2], min(curr[idx2-1], dp[idx2-1]));
                }
            }
            dp = curr;
        }
        return dp[n2];
    }
};