#include<bits/stdc++.h>
using namespace std;

class Solution {
    void solve(string s, vector<string> &ans, string curr, int idx){
        if(idx == s.length()){
            // ans.push_back(curr);
            return;
        }
        for(int i=idx; i<s.size(); i++){
            curr.push_back(s[i]);
            ans.push_back(curr);
            solve(s, ans, curr, i+1);
            curr.pop_back();
        }
        return;
    }
  public:
    vector<string> AllPossibleStrings(string s) {
        // Code here
        vector<string> ans;
        solve(s, ans, "", 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
};