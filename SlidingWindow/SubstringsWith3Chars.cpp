#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0, n = s.length(), l = 0, r = 0;
        vector<int> freq(3, 0);
        while(r < n){
            freq[s[r]-'a']++;
            while(freq[0] && freq[1] && freq[2]){
                ans += n-r;
                freq[s[l]-'a']--;
                l++;
            }
            r++;
        }
        return ans;
    }
};