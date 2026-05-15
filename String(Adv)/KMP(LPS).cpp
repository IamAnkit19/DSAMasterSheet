#include<bits/stdc++.h>
using namespace std;

class Solution {
    int computeLps(string s){
        int n = s.size();
        vector<int> p(n, 0);
        for(int i=1; i<n; i++){
            int j = p[i-1];
            if(s[j] == s[i]){
                p[i] = j+1;
            }
            else{
                while(j > 0 && s[j] != s[i]){
                    j--;
                    j = p[j];
                }
                if(s[i] == s[j]){
                    p[i] = j+1;
                }
            }
        }
        return p[n-1];
    }
public:
    string longestPrefix(string s) {
        return s.substr(0, computeLps(s));
    }
};