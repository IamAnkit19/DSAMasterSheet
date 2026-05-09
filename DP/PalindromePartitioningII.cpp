#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isPalindrome(int i, int j, string &s){
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    // Memoization
    int solve(int i, int n, string &s, vector<int> &dp){
        if(i == n){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int mini = INT_MAX;
        for(int idx=i; idx<n; idx++){
            if(isPalindrome(i, idx, s)){
                mini = min(mini, 1+solve(idx+1, n, s, dp));
            }
        }
        return dp[i] = mini;
    }
public:
    int minCut(string s) {
        int n = s.length();
        // vector<int> dp(n, -1);
        // return solve(0, n, s, dp) - 1;

        // Tabulation
        vector<int> dp(n+1, 0);
        for(int i=n-1; i>=0; i--){
            int mini = INT_MAX;
            for(int idx=i; idx<n; idx++){
                if(isPalindrome(i, idx, s)){
                    mini = min(mini, 1+dp[idx+1]);
                }
            }
            dp[i] = mini;
        }
        return dp[0] - 1;
    }
};