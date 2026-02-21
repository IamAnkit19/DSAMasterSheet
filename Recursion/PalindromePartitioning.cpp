#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isPalindrome(string &s, int start, int end){
        while(start < end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }
    void solve(string &s, vector<string> &curr, vector<vector<string>> &ans, int idx){
        if(idx == s.length()){
            ans.push_back(curr);
            return;
        }
        for(int i=idx; i<s.length(); i++){
            if(isPalindrome(s, idx, i)){
                curr.push_back(s.substr(idx, i - idx + 1));
                solve(s, curr, ans, i+1);
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        solve(s, curr, ans, 0);
        return ans;
    }
};