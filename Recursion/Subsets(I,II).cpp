#include<bits/stdc++.h>
using namespace std;

// I
class Solution {
    // Recursive
    void solve(vector<int> &nums, vector<int> curr, vector<vector<int>> &ans, int idx){
        ans.push_back(curr);
        for(int i=idx; i<nums.size(); i++){
            curr.push_back(nums[i]);
            solve(nums, curr, ans, i+1);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums, {}, ans, 0);
        return ans;
    }
};

// II
class Solution {
    void solve(vector<int> &nums, vector<vector<int>> &ans, vector<int> curr, int idx){
        if(curr.size() > 0)
            ans.push_back(curr);
        for(int i=idx; i<nums.size(); i++){
            if(i > idx && nums[i] == nums[i-1]){
                continue;
            }
            curr.push_back(nums[i]);
            solve(nums, ans, curr, i+1);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        ans.push_back({});
        solve(nums, ans, {}, 0);
        return ans;
    }
};