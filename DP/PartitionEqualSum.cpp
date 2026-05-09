#include<bits/stdc++.h>
using namespace std;

class Solution {
    // Memoization
    bool solve(int idx, int target, vector<int> &nums, vector<vector<int>> &dp){
        if(target == 0){
            return true;
        }
        if(idx == 0){
            return nums[idx] == target;
        }
        if(dp[idx][target] != -1){
            return dp[idx][target];
        }
        bool take = false;
        if(nums[idx] <= target){
            take = solve(idx-1, target-nums[idx], nums, dp);
        }
        bool notTake = solve(idx-1, target, nums, dp);
        return take || notTake;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int val : nums){
            totalSum += val;
        }
        if(totalSum % 2){
            return false;
        }
        int target = totalSum / 2;
        // vector<vector<int>> dp(n, vector<int>(target+1, -1));
        // return solve(n-1, target, nums, dp);

        // Tabulation
        // vector<vector<bool>> dp(n, vector<bool>(target+1, 0));
        // for(int i=0; i<n; i++){
        //     dp[i][0] = true;
        // }
        // if(nums[0] <= target){
        //     dp[0][nums[0]] = true;
        // }
        // for(int idx=1; idx<n; idx++){
        //     for(int t=1; t<=target; t++){
        //         bool take = false;
        //         if(nums[idx] <= t){
        //             take = dp[idx-1][t-nums[idx]];
        //         }
        //         bool notTake = dp[idx-1][t];
        //         dp[idx][t] = take || notTake;
        //     }
        // }
        // return dp[n-1][target];

        // Space Optimization
        vector<bool> dp(target+1, 0), temp(target+1, 0);
        dp[0] = temp[0] = true;
        if(nums[0] <= target){
            dp[nums[0]] = true;
        }
        for(int idx=1; idx<n; idx++){
            for(int t=1; t<=target; t++){
                bool take = false;
                if(nums[idx] <= t){
                    take = dp[t-nums[idx]];
                }
                bool notTake = dp[t];
                temp[t] = take || notTake;
            }
            dp = temp;
        }
        return dp[target];
    }
};