#include<bits/stdc++.h>
using namespace std;

// Print
class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int> dp(n, 1), hash(n);
        int maxi = 1;
        int lastIndex = 0;
        for(int i=0; i<n; i++){
            hash[i] = i;
            for(int prev=0; prev<i; prev++){
                if(arr[prev] < arr[i] && 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                lastIndex = i;
            }
        }
        vector<int> temp;
        temp.push_back(arr[lastIndex]);
        while(hash[lastIndex] != lastIndex){
            lastIndex = hash[lastIndex];
            temp.push_back(arr[lastIndex]);
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};

// Divisible
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), hash(n);
        int maxi = 1;
        int lastIndex = 0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            hash[i] = i;
            for(int prev=0; prev<i; prev++){
                if(nums[i] % nums[prev] == 0 && 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                lastIndex = i;
            }
        }
        vector<int> temp;
        temp.push_back(nums[lastIndex]);
        while(hash[lastIndex] != lastIndex){
            lastIndex = hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }
        // reverse(temp.begin(), temp.end());
        return temp;
    }
};

// Chain
class Solution {
    bool isPossible(string &a, string &b){
        if(a.size() != b.size() + 1){
            return false;
        }
        int first = 0, second = 0;
        while(first < a.size()){
            if(second < b.size() && a[first] == b[second]){
                first++;
                second++;
            }
            else{
                first++;
            }
        }
        if(first == a.size() && second == b.size()){
            return true;
        }
        return false;
    }
    static bool comp(string a, string b){
        return a.size() < b.size();
    }
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), comp);
        vector<int> dp(n, 1);
        int maxi = 1;
        for(int i=0; i<n; i++){
            for(int prev=0; prev<i; prev++){
                if(isPossible(words[i], words[prev]) && 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};

// Bitonic
class Solution {
  public:
    int longestBitonicSequence(int n, vector<int> &nums) {
        // code here
        vector<int> dp1(n, 1), dp2(n, 1);
        for(int i=0; i<n; i++){
            for(int prev=0; prev<i; prev++){
                if(nums[i] > nums[prev] && 1 + dp1[prev] > dp1[i]){
                    dp1[i] = 1 + dp1[prev];
                }
            }
        }
        for(int i=n-1; i>=0; i--){
            for(int prev=n-1; prev>i; prev--){
                if(nums[i] > nums[prev] && 1 + dp2[prev] > dp2[i]){
                    dp2[i] = 1 + dp2[prev];
                }
            }
        }
        int maxi = 0;
        for(int i=0; i<n; i++){
            if(dp1[i] > 1 && dp2[i] > 1)
            maxi = max(maxi, dp1[i]+dp2[i]-1);
        }
        return maxi;
    }
};