#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> freq(26, 0);
        int l = 0, r = 0, maxLength = 0, maxFreq = 0;
        while(r < n){
            freq[s[r]-'A']++;
            maxFreq = max(maxFreq, freq[s[r]-'A']);
            while((r-l+1)-maxFreq > k){
                freq[s[l]-'A']--;
                l++;
            }
            maxLength = max(maxLength, r-l+1);
            r++;
        }
        return maxLength;
    }
};