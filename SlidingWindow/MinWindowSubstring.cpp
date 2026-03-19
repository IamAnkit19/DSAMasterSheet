#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length(), n = t.length();
        vector<int> freq(256, 0);
        for(char c : t){
            freq[c]++;
        }
        int l = 0, r = 0, count = 0, minLength = INT_MAX, sIndex = -1;
        while(r < m){
            if(freq[s[r]] > 0){
                count++;
            }
            freq[s[r]]--;
            while(count == n){
                if(r - l + 1 < minLength){
                    minLength = r - l + 1;
                    sIndex = l;
                }
                freq[s[l]]++;
                if(freq[s[l]] > 0){
                    count--;
                }
                l++;
            }
            r++;
        }
        return sIndex == -1 ? "" : s.substr(sIndex, minLength);
    }
};