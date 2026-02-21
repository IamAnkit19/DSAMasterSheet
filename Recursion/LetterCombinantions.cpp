#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<string> letter = {
        "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
public:
    void backtrack(int idx, string &digits, string &current, vector<string> &ans){
        if(current.length() == digits.size()){
            ans.push_back(current);
            return;
        }
        string possible = letter[digits[idx] - '2'];
        for(char ch : possible){
            current.push_back(ch);
            backtrack(idx + 1, digits, current, ans);
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()) return ans;
        string current = "";
        backtrack(0, digits, current, ans);
        return ans;
    }
};