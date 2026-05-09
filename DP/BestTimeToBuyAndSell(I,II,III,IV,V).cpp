#include<bits/stdc++.h>
using namespace std;

// I
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int profit = 0;
        for(int i=1; i<prices.size(); i++){
            profit = max(profit, prices[i]-mini);
            mini = min(mini, prices[i]);
        }
        return profit;
    }
};

// II
class Solution {
    // Memoization
    int solve(int idx, bool buy, vector<int> &prices, vector<vector<int>> &dp){
        int n = prices.size();
        if(idx == n){
            return 0;
        }
        if(dp[idx][buy] != -1){
            return dp[idx][buy];
        }
        int profit = 0;
        if(buy){
            profit = max(-prices[idx]+solve(idx+1, false, prices, dp), solve(idx+1, true, prices, dp));
        }
        else{
            profit = max(prices[idx]+solve(idx+1, true, prices, dp), solve(idx+1, false, prices, dp));
        }
        return dp[idx][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n, vector<int>(2,-1));
        // return solve(0, true, prices, dp);

        // Tabulation
        // vector<vector<int>> dp(n+1, vector<int>(2,0));
        // dp[n][0] = dp[n][1] = 0;
        // for(int idx=n-1; idx>=0; idx--){
        //     for(int buy=0; buy<=1; buy++){
        //         int profit = 0;
        //         if(buy){
        //             profit = max(-prices[idx] + dp[idx+1][0], dp[idx+1][1]);
        //         }
        //         else{
        //             profit = max(prices[idx] + dp[idx+1][1], dp[idx+1][0]);
        //         }
        //         dp[idx][buy] = profit;
        //     }
        // }
        // return dp[0][1];

        // Space Optimization
        vector<int> dp(2,0);
        dp[0] = dp[1] = 0;
        for(int idx=n-1; idx>=0; idx--){
            vector<int> temp(2);
            for(int buy=0; buy<=1; buy++){
                int profit = 0;
                if(buy){
                    profit = max(-prices[idx] + dp[0], dp[1]);
                }
                else{
                    profit = max(prices[idx] + dp[1], dp[0]);
                }
                temp[buy] = profit;
            }
            dp = temp;
        }
        return dp[1];
    }
};

// III
class Solution {
    // Memoization
    int solve(int idx, bool buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp){
        int n = prices.size();
        if(idx == n || cap == 0){
            return 0;
        }
        if(dp[idx][buy][cap] != -1){
            return dp[idx][buy][cap];
        }
        int profit = 0;
        if(buy){
            profit = max(-prices[idx]+solve(idx+1, false, cap, prices, dp), solve(idx+1, true, cap, prices, dp));
        }
        else{
            profit = max(prices[idx]+solve(idx+1, true, cap-1, prices, dp), solve(idx+1, false, cap, prices, dp));
        }
        return dp[idx][buy][cap] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2,vector<int>(3,-1)));
        // return solve(0, true, 2, prices, dp);

        // Tabulation
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2,vector<int>(3,0)));
        // for(int idx=n-1; idx>=0; idx--){
        //     for(int buy=0; buy<=1; buy++){
        //         for(int cap=1; cap<=2; cap++){
        //             int profit = 0;
        //             if(buy){
        //                 profit = max(-prices[idx] + dp[idx+1][0][cap], dp[idx+1][1][cap]);
        //             }
        //             else{
        //                 profit = max(prices[idx] + dp[idx+1][1][cap-1], dp[idx+1][0][cap]);
        //             }
        //             dp[idx][buy][cap] = profit;
        //         }
        //     }
        // }
        // return dp[0][1][2];

        // Space Optimization
        vector<vector<int>> dp(2,vector<int>(3,0));
        for(int idx=n-1; idx>=0; idx--){
            vector<vector<int>> temp(2, vector<int>(3));
            for(int buy=0; buy<=1; buy++){
                for(int cap=1; cap<=2; cap++){
                    int profit = 0;
                    if(buy){
                        profit = max(-prices[idx] + dp[0][cap], dp[1][cap]);
                    }
                    else{
                        profit = max(prices[idx] + dp[1][cap-1], dp[0][cap]);
                    }
                    temp[buy][cap] = profit;
                }
            }
            dp = temp;
        }
        return dp[1][2];
    }
};

// IV
class Solution {
    // Memoization
    int solve(int idx, bool buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp){
        int n = prices.size();
        if(idx == n || cap == 0){
            return 0;
        }
        if(dp[idx][buy][cap] != -1){
            return dp[idx][buy][cap];
        }
        int profit = 0;
        if(buy){
            profit = max(-prices[idx]+solve(idx+1, false, cap, prices, dp), solve(idx+1, true, cap, prices, dp));
        }
        else{
            profit = max(prices[idx]+solve(idx+1, true, cap-1, prices, dp), solve(idx+1, false, cap, prices, dp));
        }
        return dp[idx][buy][cap] = profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2,vector<int>(k+1,-1)));
        // return solve(0, true, k, prices, dp);

        // Tabulation
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2,vector<int>(k+1,0)));
        // for(int idx=n-1; idx>=0; idx--){
        //     for(int buy=0; buy<=1; buy++){
        //         for(int cap=1; cap<=k; cap++){
        //             int profit = 0;
        //             if(buy){
        //                 profit = max(-prices[idx] + dp[idx+1][0][cap], dp[idx+1][1][cap]);
        //             }
        //             else{
        //                 profit = max(prices[idx] + dp[idx+1][1][cap-1], dp[idx+1][0][cap]);
        //             }
        //             dp[idx][buy][cap] = profit;
        //         }
        //     }
        // }
        // return dp[0][1][k];

        // Space Optimization
        vector<vector<int>> dp(2,vector<int>(k+1,0));
        for(int idx=n-1; idx>=0; idx--){
            vector<vector<int>> temp(2, vector<int>(k+1));
            for(int buy=0; buy<=1; buy++){
                for(int cap=1; cap<=k; cap++){
                    int profit = 0;
                    if(buy){
                        profit = max(-prices[idx] + dp[0][cap], dp[1][cap]);
                    }
                    else{
                        profit = max(prices[idx] + dp[1][cap-1], dp[0][cap]);
                    }
                    temp[buy][cap] = profit;
                }
            }
            dp = temp;
        }
        return dp[1][k];
    }
};

// V
class Solution {
    // Memoization
    long long solve(int idx, int state, int cap, vector<int> &prices, vector<vector<vector<long long>>> &dp){
        int n = prices.size();
        if(idx == n){
            if(state != 0) return -1e15;
            return 0;
        }
        if(cap == 0 && state == 0){
            return 0;
        }
        if(dp[idx][state][cap] != -1){
            return dp[idx][state][cap];
        }
        long long profit = 0;
        if(state == 0){
            long long doNothing = solve(idx+1, 0, cap, prices, dp);
            long long normalBuy = -prices[idx] + solve(idx+1, 1, cap-1, prices, dp);
            long long shortSell = prices[idx] + solve(idx+1, 2, cap-1, prices, dp);
            profit = max({doNothing, normalBuy, shortSell});
        }
        else if(state == 1){
            long long doNothing = solve(idx+1, 1, cap, prices, dp);
            long long sell = prices[idx] + solve(idx+1, 0, cap, prices, dp);
            profit = max(doNothing, sell);
        }
        else{
            long long doNothing = solve(idx+1, 2, cap, prices, dp);
            long long buyBack = -prices[idx] + solve(idx+1, 0, cap, prices, dp);
            profit = max(doNothing, buyBack);
        }
        return dp[idx][state][cap] = profit;
    }
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        // vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(3, vector<long long>(k+1, -1)));
        // return solve(0, 0, k, prices, dp);

        // Tabulation
        // vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(3, vector<long long>(k+1, 0)));
        // for(int cap=0; cap<=k; cap++){
        //     dp[n][1][cap] = -1e15;
        //     dp[n][2][cap] = -1e15;
        // }
        // for(int idx=n-1; idx>=0; idx--){
        //     for(int cap=0; cap<=k; cap++){
        //         if(cap == 0){
        //             dp[idx][0][cap] = 0;
        //         }
        //         else{
        //             long long doNothing = dp[idx+1][0][cap];
        //             long long normalBuy = -prices[idx] + dp[idx+1][1][cap-1];
        //             long long shortSell = prices[idx] + dp[idx+1][2][cap-1];
        //             dp[idx][0][cap] = max({doNothing, normalBuy, shortSell});
        //         }
        //         long long doNothing1 = dp[idx + 1][1][cap];
        //         long long sell = prices[idx] + dp[idx + 1][0][cap];
        //         dp[idx][1][cap] = max(doNothing1, sell);
        //         long long doNothing2 = dp[idx + 1][2][cap];
        //         long long buyBack = -prices[idx] + dp[idx + 1][0][cap];
        //         dp[idx][2][cap] = max(doNothing2, buyBack);
        //     }
        // }
        // return dp[0][0][k];

        // Space Optimization
        vector<vector<long long>> dp(3, vector<long long>(k+1, 0));
        for(int cap=0; cap<=k; cap++){
            dp[1][cap] = -1e15;
            dp[2][cap] = -1e15;
        }
        for(int idx=n-1; idx>=0; idx--){
            vector<vector<long long>> temp(3, vector<long long>(k+1, 0));
            for(int cap=0; cap<=k; cap++){
                if(cap == 0){
                    temp[0][cap] = 0;
                }
                else{
                    long long doNothing = dp[0][cap];
                    long long normalBuy = -prices[idx] + dp[1][cap-1];
                    long long shortSell = prices[idx] + dp[2][cap-1];
                    temp[0][cap] = max({doNothing, normalBuy, shortSell});
                }
                long long doNothing1 = dp[1][cap];
                long long sell = prices[idx] + dp[0][cap];
                temp[1][cap] = max(doNothing1, sell);
                long long doNothing2 = dp[2][cap];
                long long buyBack = -prices[idx] + dp[0][cap];
                temp[2][cap] = max(doNothing2, buyBack);
            }
            dp = temp;
        }
        return dp[0][k];
    }
};