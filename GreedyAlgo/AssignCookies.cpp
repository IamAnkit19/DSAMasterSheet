#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int l = 0, r = 0;
        while(l < s.size() && r < g.size()){
            if(s[l] >= g[r]){
                l++;
                r++;
            }
            else{
                l++;
            }
        }
        return r;
    }
};