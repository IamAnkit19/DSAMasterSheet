#include<bits/stdc++.h>
using namespace std;

class Solution {
    // Not Optimized
    // bool isValid(string s){
    //     int count = 0;
    //     for(char c : s){
    //         if(c == '('){
    //             count++;
    //         }
    //         else if(c == ')'){
    //             count--;
    //         }
    //         if(count < 0){
    //             return false;
    //         }
    //     }
    //     return count == 0;
    // }
    // void solve(string curr, int n, vector<string> &ans){
    //     if(curr.length() == 2*n){
    //         if(isValid(curr)){
    //             ans.push_back(curr);
    //         }
    //         return;
    //     }
    //     curr.push_back('(');
    //     solve(curr, n, ans);
    //     curr.pop_back();
    //     curr.push_back(')');
    //     solve(curr, n, ans);
    //     curr.pop_back();
    // }

    // Optimized
    void solve(string curr, int n, vector<string> &ans, int open, int close){
        if(curr.length() == 2*n){
            ans.push_back(curr);
            return;
        }
        if(open < n){
            curr.push_back('(');
            solve(curr, n, ans, open+1, close);
            curr.pop_back();
        }
        if(close < open){
            curr.push_back(')');
            solve(curr, n, ans, open, close+1);
            curr.pop_back();
        }   
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int open = 0, close = 0;
        solve("", n, ans, open, close);
        return ans;
    }
};