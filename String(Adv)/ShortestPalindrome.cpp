#include<bits/stdc++.h>
using namespace std;

class Solution {
    void computeLPS(string pattern, vector<int> &lps){
        int n = pattern.size();
        int len = 0;
        lps[0] = 0;
        int i = 1;
        while(i < n){
            if(pattern[i] == pattern[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len != 0){
                    len = lps[len-1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string temp = s + "_" + rev;
        vector<int> lps(temp.length(), 0);
        computeLPS(temp, lps);
        int longestLPSLength = lps[temp.length()-1];
        string culprit = rev.substr(0, rev.size()-longestLPSLength);
        return culprit + s;
    }
};