#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minDifference(vector<int>& arr) {
        // code here
        // Tabulation
        // int totalSum = 0;
        // for(int val : arr){
        //     totalSum += val;
        // }
        // int n = arr.size();
        // vector<vector<bool>> dp(n, vector<bool>(totalSum+1, false));
        // for(int i=0; i<n; i++){
        //     dp[i][0] = true;
        // }
        // if(arr[0] <= totalSum)
        //     dp[0][arr[0]] = true;
        // for(int idx=1; idx<n; idx++){
        //     for(int target=0; target<=totalSum; target++){
        //         bool take = false;
        //         if(arr[idx] <= target){
        //             take = dp[idx-1][target-arr[idx]];
        //         }
        //         bool notTake = dp[idx-1][target];
        //         dp[idx][target] = take || notTake;
        //     }
        // }
        // int mini = 1e8;
        // for(int i=0; i<=totalSum/2; i++){
        //     if(dp[n-1][i] == true){
        //         int s2 = totalSum - i;
        //         mini = min(mini, abs(i-s2));
        //     }
        // }
        // return mini;

        // Space Optimization
        int totalSum = 0;
        for(int val : arr){
            totalSum += val;
        }
        int n = arr.size();
        vector<bool> dp(totalSum+1, false), curr(totalSum+1, false);
        dp[0] = curr[0] = true;
        if(arr[0] <= totalSum)
            dp[arr[0]] = true;
        for(int idx=1; idx<n; idx++){
            for(int target=0; target<=totalSum; target++){
                bool take = false;
                if(arr[idx] <= target){
                    take = dp[target-arr[idx]];
                }
                bool notTake = dp[target];
                curr[target] = take || notTake;
            }
            dp = curr;
        }
        int mini = 1e8;
        for(int i=0; i<=totalSum/2; i++){
            if(dp[i] == true){
                int s2 = totalSum - i;
                mini = min(mini, abs(i-s2));
            }
        }
        return mini;
    }
};