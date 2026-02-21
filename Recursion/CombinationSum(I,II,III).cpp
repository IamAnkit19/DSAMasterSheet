#include<bits/stdc++.h>
using namespace std;

// I
class Solution {
    // Recursive
    void solve(vector<int> &candidates, vector<int> curr, vector<vector<int>> &ans, int target, int idx){
        if(idx == candidates.size()){
            if(target == 0){
                ans.push_back(curr);
            }
            return;
        }
        if(candidates[idx] <= target){
            curr.push_back(candidates[idx]);
            solve(candidates, curr, ans, target-candidates[idx], idx);
            curr.pop_back();
        }
        solve(candidates, curr, ans, target, idx+1);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        solve(candidates, {}, ans, target, 0);
        return ans;
    }
};

// II
class Solution {
    // Recursive
    void solve(vector<int> &candidates, vector<int> curr, vector<vector<int>> &ans, int target, int idx){
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        for(int i=idx; i<candidates.size(); i++){
            if(i > idx && candidates[i] == candidates[i-1])
                continue;
            if(candidates[i] > target)
                break;
            curr.push_back(candidates[i]);
            solve(candidates, curr, ans, target-candidates[i], i+1);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        solve(candidates, {}, ans, target, 0);
        return ans;
    }
};