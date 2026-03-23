#include<bits/stdc++.h>
using namespace std;

// Minimums
class Solution {
    vector<int> findNSE(vector<int> &nums){
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            else{
                ans[i] = n;
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> findPSE(vector<int> &nums){
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            else{
                ans[i] = -1;
            }
            st.push(i);
        }
        return ans;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSE(arr);
        int n = arr.size();
        int ans = 0;
        int mod = 1e9 + 7;
        for(int i=0; i<n; i++){
            int left = i - pse[i];
            int right = nse[i] - i;
            long long freq = left*right*1LL;
            int val = (freq*arr[i]*1LL) % mod;
            ans = (ans + val) % mod;
        }
        return ans;
    }
};

// Ranges
class Solution {
    vector<int> findNSE(vector<int> &nums){
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            else{
                ans[i] = n;
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> findPSE(vector<int> &nums){
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            else{
                ans[i] = -1;
            }
            st.push(i);
        }
        return ans;
    }
    long long sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSE(arr);
        int n = arr.size();
        long long ans = 0;
        for(int i=0; i<n; i++){
            int left = i - pse[i];
            int right = nse[i] - i;
            ans += (long long)arr[i] * left * right;
        }
        return ans;
    }
    vector<int> findNGE(vector<int> &nums){
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            else{
                ans[i] = n;
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> findPGE(vector<int> &nums){
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            else{
                ans[i] = -1;
            }
            st.push(i);
        }
        return ans;
    }
    long long sumSubarrayMax(vector<int>& arr) {
        vector<int> nge = findNGE(arr);
        vector<int> pge = findPGE(arr);
        int n = arr.size();
        long long ans = 0;
        for(int i=0; i<n; i++){
            int left = i - pge[i];
            int right = nge[i] - i;
            ans += (long long)arr[i] * left * right;
        }
        return ans;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMax(nums) - sumSubarrayMins(nums);
    }
};